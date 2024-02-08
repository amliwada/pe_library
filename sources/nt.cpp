#include <pe_library/nt.hpp>

std::uint16_t pe_library::nt::get_machine() const noexcept
{
	return this->_machine;
}

void pe_library::nt::set_machine(std::uint16_t value) noexcept
{
	this->_machine = value;
}

std::uint32_t pe_library::nt::get_time_date_stamp() const noexcept
{
	return this->_time_date_stamp;
}

void pe_library::nt::set_time_date_stamp(std::uint32_t value) noexcept
{
	this->_time_date_stamp = value;
}

std::uint16_t pe_library::nt::get_characteristics() const noexcept
{
	return this->_characteristics;
}

void pe_library::nt::set_characteristics(std::uint16_t value) noexcept
{
	this->_characteristics = value;
}

std::uint16_t pe_library::nt::get_magic() const noexcept
{
	return this->_magic;
}

void pe_library::nt::set_magic(std::uint16_t value) noexcept
{
	this->_magic = value;
}

std::uint8_t pe_library::nt::get_major_linker_version() const noexcept
{
	return this->_major_linker_version;
}

void pe_library::nt::set_major_linker_version(std::uint8_t value) noexcept
{
	this->_major_linker_version = value;
}

std::uint8_t pe_library::nt::get_minor_linker_version() const noexcept
{
	return this->_minor_linker_version;
}

void pe_library::nt::set_minor_linker_version(std::uint8_t value) noexcept
{
	this->_minor_linker_version = value;
}

pe_library::details::sections_container::iterator const& pe_library::nt::get_data_section() const noexcept
{
	return this->_data_section;
}

void pe_library::nt::set_data_section(details::sections_container::iterator value) noexcept
{
	this->_data_section = value;
}

pe_library::details::sections_container::iterator const& pe_library::nt::get_code_section() const noexcept
{
	return this->_code_section;
}

void pe_library::nt::set_code_section(details::sections_container::iterator value) noexcept
{
	this->_code_section = value;
}

pe_library::data_address const& pe_library::nt::get_entry_point_address() const noexcept
{
	return this->_entry_point_address;
}

void pe_library::nt::set_entry_point_address(pe_library::data_address&& value) noexcept
{
	this->_entry_point_address = std::move(value);
}

std::uint64_t pe_library::nt::get_image_base() const noexcept
{
	return this->_image_base;
}

void pe_library::nt::set_image_base(std::uint64_t value) noexcept
{
	this->_image_base = value;
}

std::uint32_t pe_library::nt::get_section_alignment() const noexcept
{
	return this->_section_alignment;
}

void pe_library::nt::set_section_alignment(std::uint32_t value) noexcept
{
	this->_section_alignment = value;
}

std::uint32_t pe_library::nt::get_file_alignment() const noexcept
{
	return this->_file_alignment;
}

void pe_library::nt::set_file_alignment(std::uint32_t value) noexcept
{
	this->_file_alignment = value;
}

std::uint16_t pe_library::nt::get_major_operating_system_version() const noexcept
{
	return this->_major_operating_system_version;
}

void pe_library::nt::set_major_operating_system_version(std::uint16_t value) noexcept
{
	this->_major_operating_system_version = value;
}

std::uint16_t pe_library::nt::get_minor_operating_system_version() const noexcept
{
	return this->_minor_operating_system_version;
}

void pe_library::nt::set_minor_operating_system_version(std::uint16_t value) noexcept
{
	this->_minor_operating_system_version = value;
}

std::uint16_t pe_library::nt::get_major_image_version() const noexcept
{
	return this->_major_image_version;
}

void pe_library::nt::set_major_image_version(std::uint16_t value) noexcept
{
	this->_major_image_version = value;
}

std::uint16_t pe_library::nt::get_minor_image_version() const noexcept
{
	return this->_minor_image_version;
}

void pe_library::nt::set_minor_image_version(std::uint16_t value) noexcept
{
	this->_minor_image_version = value;
}

std::uint16_t pe_library::nt::get_major_subsystem_version() const noexcept
{
	return this->_major_subsystem_version;
}

void pe_library::nt::set_major_subsystem_version(std::uint16_t value) noexcept
{
	this->_major_subsystem_version = value;
}

std::uint16_t pe_library::nt::get_minor_subsystem_version() const noexcept
{
	return this->_minor_subsystem_version;
}

void pe_library::nt::set_minor_subsystem_version(std::uint16_t value) noexcept
{
	this->_minor_subsystem_version = value;
}

std::uint32_t pe_library::nt::get_win32_version_value() const noexcept
{
	return this->_win32_version_value;
}

void pe_library::nt::set_win32_version_value(std::uint32_t value) noexcept
{
	this->_win32_version_value = value;
}

std::uint32_t pe_library::nt::get_checksum() const noexcept
{
	return this->_checksum;
}

void pe_library::nt::set_checksum(std::uint32_t value) noexcept
{
	this->_checksum = value;
}

std::uint16_t pe_library::nt::get_subsystem() const noexcept
{
	return this->_subsystem;
}

void pe_library::nt::set_subsystem(std::uint16_t value) noexcept
{
	this->_subsystem = value;
}

std::uint16_t pe_library::nt::get_dll_characteristics() const noexcept
{
	return this->_dll_characteristics;
}

void pe_library::nt::set_dll_characteristics(std::uint16_t value) noexcept
{
	this->_dll_characteristics = value;
}

std::uint64_t pe_library::nt::get_size_of_stack_reserve() const noexcept
{
	return this->_size_of_stack_reserve;
}

void pe_library::nt::set_size_of_stack_reserve(std::uint64_t value) noexcept
{
	this->_size_of_stack_reserve = value;
}

std::uint64_t pe_library::nt::get_size_of_stack_commit() const noexcept
{
	return this->_size_of_stack_commit;
}

void pe_library::nt::set_size_of_stack_commit(std::uint64_t value) noexcept
{
	this->_size_of_stack_commit = value;
}

std::uint64_t pe_library::nt::get_size_of_heap_reserve() const noexcept
{
	return this->_size_of_heap_reserve;
}

void pe_library::nt::set_size_of_heap_reserve(std::uint64_t value) noexcept
{
	this->_size_of_heap_reserve = value;
}

std::uint64_t pe_library::nt::get_size_of_heap_commit() const noexcept
{
	return this->_size_of_heap_commit;
}

void pe_library::nt::set_size_of_heap_commit(std::uint64_t value) noexcept
{
	this->_size_of_heap_commit = value;
}

std::uint32_t pe_library::nt::get_loader_flags() const noexcept
{
	return this->_loader_flags;
}

void pe_library::nt::set_loader_flags(std::uint32_t value) noexcept
{
	this->_loader_flags = value;
}

std::array<std::optional<pe_library::data_address>, pe_library::details::headers::constants::nt_headers::number_of_directory_entries> const& pe_library::nt::get_data_directory() const noexcept
{
	return this->_data_directory;
}

void pe_library::nt::set_export_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_export] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_export() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_export];
}

void pe_library::nt::set_import_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_import] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_import() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_import];
}

void pe_library::nt::set_resource_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_resource] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_resource() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_resource];
}

void pe_library::nt::set_exception_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_exception] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_exception() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_exception];
}

void pe_library::nt::set_security_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_security] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_security() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_security];
}

void pe_library::nt::set_basereloc_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_basereloc] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_basereloc() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_basereloc];
}

void pe_library::nt::set_debug_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_debug] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_debug() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_debug];
}

void pe_library::nt::set_architecture_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_architecture] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_architecture() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_architecture];
}

void pe_library::nt::set_globalptr_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_globalptr] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_globalptr() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_globalptr];
}

void pe_library::nt::set_tls_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_tls] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_tls() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_tls];
}

void pe_library::nt::set_load_config_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_load_config] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_load_config() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_load_config];
}

void pe_library::nt::set_bound_import_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_bound_import] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_bound_import() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_bound_import];
}

void pe_library::nt::set_iat_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_iat] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_iat() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_iat];
}

void pe_library::nt::set_delay_import_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_delay_import] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_delay_import() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_delay_import];
}

void pe_library::nt::set_com_descriptor_address(std::optional<data_address> value) noexcept
{
	this->_data_directory[details::headers::constants::nt_headers::directory_entry_com_descriptor] = value;
}

std::optional<pe_library::data_address> const& pe_library::nt::get_com_descriptor() const noexcept
{
	return this->_data_directory[details::headers::constants::nt_headers::directory_entry_com_descriptor];
}