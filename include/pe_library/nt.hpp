#ifndef PE_LIBRARY_NT_HPP
#define PE_LIBRARY_NT_HPP

#include <array>
#include <optional>

#include <pe_library/data_address.hpp>
#include <pe_library/details/constants/nt_constants.hpp>

namespace pe_library
{
	class nt
	{
	public:
		std::uint16_t get_machine() const noexcept;
		void set_machine(std::uint16_t value) noexcept;

		std::uint32_t get_time_date_stamp() const noexcept;
		void set_time_date_stamp(std::uint32_t value) noexcept;

		std::uint16_t get_characteristics() const noexcept;
		void set_characteristics(std::uint16_t value) noexcept;

		std::uint16_t get_magic() const noexcept;
		void set_magic(std::uint16_t value) noexcept;

		std::uint8_t get_major_linker_version() const noexcept;
		void set_major_linker_version(std::uint8_t value) noexcept;

		std::uint8_t get_minor_linker_version() const noexcept;
		void set_minor_linker_version(std::uint8_t value) noexcept;

		details::sections_container::iterator const& get_data_section() const noexcept;
		void set_data_section(details::sections_container::iterator value) noexcept;

		details::sections_container::iterator const& get_code_section() const noexcept;
		void set_code_section(details::sections_container::iterator value) noexcept;

		data_address const& get_entry_point_address() const noexcept;
		void set_entry_point_address(data_address&& value) noexcept;

		std::uint64_t get_image_base() const noexcept;
		void set_image_base(std::uint64_t value) noexcept;

		std::uint32_t get_section_alignment() const noexcept;
		void set_section_alignment(std::uint32_t value) noexcept;

		std::uint32_t get_file_alignment() const noexcept;
		void set_file_alignment(std::uint32_t value) noexcept;

		std::uint16_t get_major_operating_system_version() const noexcept;
		void set_major_operating_system_version(std::uint16_t value) noexcept;

		std::uint16_t get_minor_operating_system_version() const noexcept;
		void set_minor_operating_system_version(std::uint16_t value) noexcept;

		std::uint16_t get_major_image_version() const noexcept;
		void set_major_image_version(std::uint16_t value) noexcept;

		std::uint16_t get_minor_image_version() const noexcept;
		void set_minor_image_version(std::uint16_t value) noexcept;

		std::uint16_t get_major_subsystem_version() const noexcept;
		void set_major_subsystem_version(std::uint16_t value) noexcept;

		std::uint16_t get_minor_subsystem_version() const noexcept;
		void set_minor_subsystem_version(std::uint16_t value) noexcept;

		std::uint32_t get_win32_version_value() const noexcept;
		void set_win32_version_value(std::uint32_t value) noexcept;

		std::uint32_t get_checksum() const noexcept;
		void set_checksum(std::uint32_t value) noexcept;

		std::uint16_t get_subsystem() const noexcept;
		void set_subsystem(std::uint16_t value) noexcept;

		std::uint16_t get_dll_characteristics() const noexcept;
		void set_dll_characteristics(std::uint16_t value) noexcept;

		std::uint64_t get_size_of_stack_reserve() const noexcept;
		void set_size_of_stack_reserve(std::uint64_t value) noexcept;

		std::uint64_t get_size_of_stack_commit() const noexcept;
		void set_size_of_stack_commit(std::uint64_t value) noexcept;

		std::uint64_t get_size_of_heap_reserve() const noexcept;
		void set_size_of_heap_reserve(std::uint64_t value) noexcept;

		std::uint64_t get_size_of_heap_commit() const noexcept;
		void set_size_of_heap_commit(std::uint64_t value) noexcept;

		std::uint32_t get_loader_flags() const noexcept;
		void set_loader_flags(std::uint32_t value) noexcept;

		std::array<std::optional<data_address>, details::headers::constants::nt_headers::number_of_directory_entries> const& get_data_directory() const noexcept;

		template<std::size_t size>
		void set_data_directory(std::array<std::optional<data_address>, size> value) noexcept
		{
			static_assert(size == details::headers::constants::nt_headers::number_of_directory_entries);

			std::copy(value.begin(), value.end(), this->_data_directory.begin());
		}

		void set_export_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_export() const noexcept;

		void set_import_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_import() const noexcept;

		void set_resource_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_resource() const noexcept;

		void set_exception_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_exception() const noexcept;

		void set_security_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_security() const noexcept;

		void set_basereloc_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_basereloc() const noexcept;

		void set_debug_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_debug() const noexcept;

		void set_architecture_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_architecture() const noexcept;

		void set_globalptr_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_globalptr() const noexcept;

		void set_tls_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_tls() const noexcept;

		void set_load_config_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_load_config() const noexcept;

		void set_bound_import_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_bound_import() const noexcept;

		void set_iat_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_iat() const noexcept;

		void set_delay_import_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_delay_import() const noexcept;

		void set_com_descriptor_address(std::optional<data_address> value) noexcept;
		std::optional<data_address> const& get_com_descriptor() const noexcept;

	private:
		std::uint16_t _machine;
		std::uint32_t _time_date_stamp;
		std::uint16_t _characteristics;
		std::uint16_t _magic;
		std::uint8_t _major_linker_version;
		std::uint8_t _minor_linker_version;
		details::sections_container::iterator _data_section;
		details::sections_container::iterator _code_section;
		data_address _entry_point_address;
		std::uint64_t _image_base;
		std::uint32_t _section_alignment;
		std::uint32_t _file_alignment;
		std::uint16_t _major_operating_system_version;
		std::uint16_t _minor_operating_system_version;
		std::uint16_t _major_image_version;
		std::uint16_t _minor_image_version;
		std::uint16_t _major_subsystem_version;
		std::uint16_t _minor_subsystem_version;
		std::uint32_t _win32_version_value;
		std::uint32_t _checksum;
		std::uint16_t _subsystem;
		std::uint16_t _dll_characteristics;
		std::uint64_t _size_of_stack_reserve;
		std::uint64_t _size_of_stack_commit;
		std::uint64_t _size_of_heap_reserve;
		std::uint64_t _size_of_heap_commit;
		std::uint32_t _loader_flags;
		std::array<std::optional<data_address>, details::headers::constants::nt_headers::number_of_directory_entries> _data_directory;
	};
}

#endif