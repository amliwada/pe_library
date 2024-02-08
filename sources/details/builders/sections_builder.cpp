#include <ciso646>

#include <pe_library/details/builders/sections_builder.hpp>
#include <pe_library/details/headers/image_section_header.hpp>
#include <pe_library/details/helpers/bytes_helper.hpp>

std::size_t pe_library::details::builders::sections_builder::get_headers_size(file const& target_file) const noexcept
{
	auto number_of_sections{ target_file.get_sections().size() + 1};
	return number_of_sections * sizeof(headers::image_section_header);
}

void pe_library::details::builders::sections_builder::make_headers_bytecode(file const& target_file, std::uint64_t address_of_first_section)
{
	this->_size_of_code = 0;
	this->_size_of_initialized_data = 0;
	this->_size_of_uninitialized_data = 0;

	this->_nt = &target_file.get_nt();

	this->_raw_address = address_of_first_section;
	this->_virtual_address = helpers::bytes_helper::align_up(this->_raw_address, this->_nt->get_section_alignment());

	decltype(auto) sections{ target_file.get_sections() };

	for (decltype(auto) section_iterator{ sections.cbegin()}; section_iterator not_eq sections.cend(); ++section_iterator)
	{
		auto header{ this->make_section_header(*section_iterator) };

		this->_headers.emplace_back(std::make_pair(section_iterator, header));

		this->_raw_address += header.size_of_raw_data;
		this->_virtual_address += helpers::bytes_helper::align_up(header.virtual_size, this->_nt->get_section_alignment());

		auto header_begin{ reinterpret_cast<char const* const>(&header) };
		std::copy(header_begin, header_begin + sizeof(header), std::back_inserter(this->_headers_bytecode));

		if (header.characteristics bitand headers::constants::section_header::cnt_code)
		{
			this->_size_of_code += header.size_of_raw_data;
		}
		else if (header.characteristics bitand headers::constants::section_header::cnt_initialized_data)
		{
			this->_size_of_initialized_data += (std::max)(header.size_of_raw_data, header.virtual_size);
		}
		else if (header.characteristics bitand headers::constants::section_header::cnt_uninitialized_data)
		{
			this->_size_of_uninitialized_data += header.size_of_raw_data;
		}
	}

	this->_size_of_code = helpers::bytes_helper::align_up(this->_size_of_code, this->_nt->get_file_alignment());
	this->_size_of_initialized_data = helpers::bytes_helper::align_up(this->_size_of_initialized_data, this->_nt->get_file_alignment());
	this->_size_of_uninitialized_data = helpers::bytes_helper::align_up(this->_size_of_uninitialized_data, this->_nt->get_file_alignment());
}

pe_library::details::headers::image_section_header pe_library::details::builders::sections_builder::make_section_header(section const& sec) const noexcept
{
	headers::image_section_header header{ 0 };
	header.characteristics = sec.get_characteristics();

	decltype(auto) section_name{ sec.get_name() };
	std::memset(reinterpret_cast<char*>(header.name), 0, headers::constants::section_header::size_of_short_name);
	std::memcpy(reinterpret_cast<char*>(header.name), section_name.data(), (std::min)(section_name.length(), static_cast<std::size_t>(headers::constants::section_header::size_of_short_name)));

	header.pointer_to_raw_data = static_cast<std::uint32_t>(this->_raw_address);
	header.virtual_address = static_cast<std::uint32_t>(this->_virtual_address);

	decltype(auto) section_bytecode{ sec.get_bytecode() };

	if (section_bytecode.size() > 0)
	{
		auto virtual_size = sec.get_virtual_size();

		if (virtual_size == 0)
		{
			virtual_size = static_cast<std::uint32_t>(section_bytecode.size());
		}

		header.virtual_size = virtual_size;
		header.size_of_raw_data = static_cast<std::uint32_t>(helpers::bytes_helper::align_up(section_bytecode.size(), this->_nt->get_file_alignment()));
	}
	else
	{
		header.size_of_raw_data = 0;
	}

	return header;
}

std::size_t pe_library::details::builders::sections_builder::get_size_of_image() const noexcept
{
	return this->_virtual_address;
}

std::uint64_t pe_library::details::builders::sections_builder::data_address_to_imm(data_address const& address, reference_type type) const
{
	std::uint64_t result{ 0 };

	if (type == reference_type::virtual_address)
	{
		result += this->_nt->get_image_base();
	}

	for (auto const& header : this->_headers)
	{
		if (header.first->get_name() == address.get_section_iterator()->get_name())
		{
			result += header.second.virtual_address;
			break;
		}
	}

	result += address.get_data_interval_iterator()->get_position();

	return result;
}

std::uint64_t pe_library::details::builders::sections_builder::get_size_of_code() const noexcept
{
	return this->_size_of_code;
}

std::uint64_t pe_library::details::builders::sections_builder::get_size_of_initialized_data() const noexcept
{
	return this->_size_of_initialized_data;
}

std::uint64_t pe_library::details::builders::sections_builder::get_size_of_uninitialized_data() const noexcept
{
	return this->_size_of_uninitialized_data;
}

std::uint64_t pe_library::details::builders::sections_builder::get_section_virtual_address(sections_container::iterator section_iterator) const
{
	for (auto const& header : this->_headers)
	{
		if (header.first->get_name() == section_iterator->get_name())
		{
			return header.second.virtual_address;
		}
	}

	throw std::exception{ "section not found" };
}

pe_library::bytecode const& pe_library::details::builders::sections_builder::get_headers_bytecode() const noexcept
{
	return this->_headers_bytecode;
}