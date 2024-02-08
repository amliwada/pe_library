#include <ciso646>

#include <pe_library/details/parsers/sections_parser.hpp>
#include <pe_library/details/helpers/intervals_helper.hpp>

void pe_library::details::parsers::sections_parser::parse_sections(std::ifstream* file_stream)
{
	this->_file_stream = file_stream;

	this->read_section_header();

	while (this->is_valid_section_header())
	{
		this->add_section();
		this->read_section_header();
	}
}

bool pe_library::details::parsers::sections_parser::is_valid_section_header()
{
	return this->_parsed_section_header.virtual_address not_eq 0;
}

void pe_library::details::parsers::sections_parser::read_section_header()
{
	this->_file_stream->read(reinterpret_cast<char*>(&this->_parsed_section_header), sizeof(this->_parsed_section_header));

	if (this->_file_stream->bad() or this->_file_stream->eof())
	{
		throw std::exception{ "no sections" };
	}
}

void pe_library::details::parsers::sections_parser::add_section()
{
	auto name_length{ std::strlen(this->_parsed_section_header.name)};
	std::string section_name{ this->_parsed_section_header.name, this->_parsed_section_header.name + name_length };
	
	bytecode section_bytecode;
	
	if (this->_parsed_section_header.size_of_raw_data not_eq 0)
	{
		section_bytecode = this->read_section_bytecode();
	}

	section parsed_section{ std::move(section_name), std::move(section_bytecode) };
	
	parsed_section.set_characteristics(this->_parsed_section_header.characteristics);
	parsed_section.set_virtual_size(this->_parsed_section_header.virtual_size);

	auto parsed_section_iterator{ this->_parsed_sections.add_section(std::move(parsed_section)) };
	this->_headers.emplace_back(std::make_pair(this->_parsed_section_header, parsed_section_iterator));
}

pe_library::bytecode pe_library::details::parsers::sections_parser::read_section_bytecode()
{
	auto header_position{ this->_file_stream->tellg() };

	auto size_of_bytecode{ (std::min)(this->_parsed_section_header.virtual_size, this->_parsed_section_header.size_of_raw_data) };
	bytecode result(size_of_bytecode);

	this->_file_stream->seekg(this->_parsed_section_header.pointer_to_raw_data, std::ios::beg);
	this->_file_stream->read(reinterpret_cast<char*>(result.data()), result.size());

	if (this->_file_stream->bad() or this->_file_stream->eof())
	{
		throw std::exception{ "section code not found" };
	}

	this->_file_stream->seekg(header_position, std::ios::beg);

	return result;
}

pe_library::details::sections_container&& pe_library::details::parsers::sections_parser::get_parsed_sections() noexcept
{
	return std::move(this->_parsed_sections);
}

std::optional<pe_library::data_address> pe_library::details::parsers::sections_parser::rva_to_data_address(std::uint64_t rva) const noexcept
{
	for (auto const& section_header_iterator_pair : this->_headers)
	{
		auto const& section_header{ section_header_iterator_pair.first };
		
		if (this->is_address_in_section(rva, section_header))
		{
			rva -= section_header.virtual_address;
			interval data_interval{ rva, 1 };
			auto data_interval_iterator{ section_header_iterator_pair.second->add_data_interval(data_interval) };
			data_address result{ section_header_iterator_pair.second, data_interval_iterator };
			return result;
		}
	}

	return std::nullopt;
}

bool pe_library::details::parsers::sections_parser::is_address_in_section(std::uint64_t address, headers::image_section_header section_header) const noexcept
{
	interval section_interval{ section_header.virtual_address, section_header.virtual_size };
	return helpers::intervals_helper::is_position_between_interval(address, section_interval);
}