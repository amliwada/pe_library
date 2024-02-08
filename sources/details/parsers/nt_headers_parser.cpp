#include <pe_library/details/parsers/nt_headers_parser.hpp>

#include <ciso646>

void pe_library::details::parsers::nt_headers_parser::parse_headers(std::ifstream* file_stream)
{
	this->_file_stream = file_stream;

	this->check_signature_validation();
	this->read_file_header();
	this->read_optional_header();
}

bool pe_library::details::parsers::nt_headers_parser::is_nt32() const noexcept
{
	return this->_magic == headers::constants::nt_headers::optional_header_magic_32;
}

bool pe_library::details::parsers::nt_headers_parser::is_nt64() const noexcept
{
	return this->_magic == headers::constants::nt_headers::optional_header_magic_64;
}

void pe_library::details::parsers::nt_headers_parser::check_signature_validation()
{
	std::uint32_t signature;

	this->_file_stream->read(reinterpret_cast<char*>(&signature), sizeof(signature));

	if (this->_file_stream->bad() or this->_file_stream->eof())
	{
		throw std::exception{ "no nt headers" };
	}
	else if (signature not_eq details::headers::constants::nt_headers::nt_signature)
	{
		throw std::exception{ "bad nt signature" };
	}
}

void pe_library::details::parsers::nt_headers_parser::read_file_header()
{
	this->_file_stream->read(reinterpret_cast<char*>(&this->_file_header), sizeof(this->_file_header));

	if (this->_file_stream->bad() or this->_file_stream->eof())
	{
		throw std::exception{ "no nt headers" };
	}
}

void pe_library::details::parsers::nt_headers_parser::read_optional_header()
{
	auto optional_header_position{ this->_file_stream->tellg() };

	this->read_magic();

	this->_file_stream->seekg(optional_header_position, std::ios::beg);

	if (this->is_nt32())
	{
		this->read_optional_header<headers::image_optional_header32>();
	}
	else if (this->is_nt64())
	{
		this->read_optional_header<headers::image_optional_header64>();
	}
	else
	{
		throw std::exception{ "bad optional header" };
	}
}

void pe_library::details::parsers::nt_headers_parser::read_magic()
{
	this->_file_stream->read(reinterpret_cast<char*>(&this->_magic), sizeof(this->_magic));

	if (this->_file_stream->bad() or this->_file_stream->eof())
	{
		throw std::exception{ "no nt headers" };
	}
}

std::uint16_t pe_library::details::parsers::nt_headers_parser::get_magic() const noexcept
{
	return this->_magic;
}

std::uint8_t pe_library::details::parsers::nt_headers_parser::get_major_linker_version() const noexcept
{
	return this->_major_linker_version;
}

std::uint8_t pe_library::details::parsers::nt_headers_parser::get_minor_linker_version() const noexcept
{
	return this->_minor_linker_version;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_size_of_code() const noexcept
{
	return this->_size_of_code;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_size_of_initialized_data() const noexcept
{
	return this->_size_of_initialized_data;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_size_of_uninitialized_data() const noexcept
{
	return this->_size_of_uninitialized_data;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_address_of_entry_point() const noexcept
{
	return this->_address_of_entry_point;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_base_of_code() const noexcept
{
	return this->_base_of_code;
}

std::optional<std::uint32_t> pe_library::details::parsers::nt_headers_parser::get_base_of_data() const noexcept
{
	return this->_base_of_data;
}

std::uint64_t pe_library::details::parsers::nt_headers_parser::get_image_base() const noexcept
{
	return this->_image_base;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_section_alignment() const noexcept
{
	return this->_section_alignment;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_file_alignment() const noexcept
{
	return this->_file_alignment;
}

std::uint16_t pe_library::details::parsers::nt_headers_parser::get_major_operating_system_version() const noexcept
{
	return this->_major_operating_system_version;
}

std::uint16_t pe_library::details::parsers::nt_headers_parser::get_minor_operating_system_version() const noexcept
{
	return this->_minor_operating_system_version;
}

std::uint16_t pe_library::details::parsers::nt_headers_parser::get_major_image_version() const noexcept
{
	return this->_major_image_version;
}

std::uint16_t pe_library::details::parsers::nt_headers_parser::get_minor_image_version() const noexcept
{
	return this->_major_image_version;
}

std::uint16_t pe_library::details::parsers::nt_headers_parser::get_major_subsystem_version() const noexcept
{
	return this->_major_subsystem_version;
}

std::uint16_t pe_library::details::parsers::nt_headers_parser::get_minor_subsystem_version() const noexcept
{
	return this->_minor_subsystem_version;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_win32_version_value() const noexcept
{
	return this->_win32_version_value;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_size_of_image() const noexcept
{
	return this->_size_of_image;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_size_of_headers() const noexcept
{
	return this->_size_of_headers;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_checksum() const noexcept
{
	return this->_checksum;
}

std::uint16_t pe_library::details::parsers::nt_headers_parser::get_subsystem() const noexcept
{
	return this->_subsystem;
}

std::uint16_t pe_library::details::parsers::nt_headers_parser::get_dll_characteristics() const noexcept
{
	return this->_dll_characteristics;
}

std::uint64_t pe_library::details::parsers::nt_headers_parser::get_size_of_stack_reserve() const noexcept
{
	return this->_size_of_stack_reserve;
}

std::uint64_t pe_library::details::parsers::nt_headers_parser::get_size_of_stack_commit() const noexcept
{
	return this->_size_of_stack_commit;
}

std::uint64_t pe_library::details::parsers::nt_headers_parser::get_size_of_heap_reserve() const noexcept
{
	return this->_size_of_heap_reserve;
}

std::uint64_t pe_library::details::parsers::nt_headers_parser::get_size_of_heap_commit() const noexcept
{
	return this->_size_of_heap_commit;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_loader_flags() const noexcept
{
	return this->_loader_flags;
}

std::uint32_t pe_library::details::parsers::nt_headers_parser::get_number_of_rva_and_sizes() const noexcept
{
	return this->_number_of_rva_and_sizes;
}

pe_library::nt pe_library::details::parsers::nt_headers_parser::make_nt(addresses_provider* addresses_provider)
{
	nt result;

	result.set_machine(this->_file_header.machine);
	result.set_time_date_stamp(this->_file_header.time_date_stamp);
	result.set_characteristics(this->_file_header.characteristics);
	result.set_magic(this->_magic);
	result.set_major_linker_version(this->_major_linker_version);
	result.set_minor_linker_version(this->_minor_linker_version);

	if (this->_base_of_data.has_value())
	{
		auto base_of_data_address{ addresses_provider->imm_to_data_address(this->_base_of_data.value()) };
		result.set_data_section(base_of_data_address.value().get_section_iterator());
	}

	auto base_of_code_address{ addresses_provider->imm_to_data_address(this->_base_of_code) };
	result.set_code_section(base_of_code_address.value().get_section_iterator());

	auto entry_point_address{ addresses_provider->imm_to_data_address(this->_address_of_entry_point) };
	result.set_entry_point_address(std::move(*entry_point_address));

	result.set_image_base(this->_image_base);
	result.set_section_alignment(this->_section_alignment);
	result.set_file_alignment(this->_file_alignment);
	result.set_major_operating_system_version(this->_major_operating_system_version);
	result.set_minor_operating_system_version(this->_minor_operating_system_version);
	result.set_major_image_version(this->_major_image_version);
	result.set_minor_image_version(this->_minor_image_version);
	result.set_major_subsystem_version(this->_major_subsystem_version);
	result.set_minor_subsystem_version(this->_minor_subsystem_version);
	result.set_win32_version_value(this->_win32_version_value);
	result.set_checksum(this->_checksum);
	result.set_subsystem(this->_subsystem);
	result.set_dll_characteristics(this->_dll_characteristics);
	result.set_size_of_stack_reserve(this->_size_of_stack_reserve);
	result.set_size_of_stack_commit(this->_size_of_stack_commit);
	result.set_size_of_heap_reserve(this->_size_of_heap_reserve);
	result.set_size_of_heap_commit(this->_size_of_heap_commit);
	result.set_loader_flags(this->_loader_flags);

	std::array<std::optional<pe_library::data_address>, details::headers::constants::nt_headers::number_of_directory_entries> data_directry;

	for (int i{ 0 }; i < details::headers::constants::nt_headers::number_of_directory_entries; ++i)
	{
		auto entry_address{ addresses_provider->imm_to_data_address(this->_data_directory[i].virtual_address) };
		
		if (entry_address.has_value())
		{
			entry_address->get_data_interval_iterator()->set_size(this->_data_directory[i].size);
		}

		data_directry[i] = entry_address;
	}

	result.set_data_directory(data_directry);

	return result;
}