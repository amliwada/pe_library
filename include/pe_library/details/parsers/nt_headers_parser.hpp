#ifndef PE_LIBRARY_NT_HEADERS_PARSER_HPP
#define PE_LIBRARY_NT_HEADERS_PARSER_HPP

#include <fstream>
#include <optional>
#include <array>

#include <pe_library/details/headers/image_nt_headers32.hpp>
#include <pe_library/details/headers/image_nt_headers64.hpp>
#include <pe_library/nt.hpp>
#include <pe_library/details/providers/addresses_provider.hpp>

namespace pe_library::details::parsers
{
	class nt_headers_parser
	{
	public:
		void parse_headers(std::ifstream* file_stream);
		
		std::uint16_t get_magic() const noexcept;
		std::uint8_t get_major_linker_version() const noexcept;
		std::uint8_t get_minor_linker_version() const noexcept;
		std::uint32_t get_size_of_code() const noexcept;
		std::uint32_t get_size_of_initialized_data() const noexcept;
		std::uint32_t get_size_of_uninitialized_data() const noexcept;
		std::uint32_t get_address_of_entry_point() const noexcept;
		std::uint32_t get_base_of_code() const noexcept;
		std::optional<std::uint32_t> get_base_of_data() const noexcept;
		std::uint64_t get_image_base() const noexcept;
		std::uint32_t get_section_alignment() const noexcept;
		std::uint32_t get_file_alignment() const noexcept;
		std::uint16_t get_major_operating_system_version() const noexcept;
		std::uint16_t get_minor_operating_system_version() const noexcept;
		std::uint16_t get_major_image_version() const noexcept;
		std::uint16_t get_minor_image_version() const noexcept;
		std::uint16_t get_major_subsystem_version() const noexcept;
		std::uint16_t get_minor_subsystem_version() const noexcept;
		std::uint32_t get_win32_version_value() const noexcept;
		std::uint32_t get_size_of_image() const noexcept;
		std::uint32_t get_size_of_headers() const noexcept;
		std::uint32_t get_checksum() const noexcept;
		std::uint16_t get_subsystem() const noexcept;
		std::uint16_t get_dll_characteristics() const noexcept;
		std::uint64_t get_size_of_stack_reserve() const noexcept;
		std::uint64_t get_size_of_stack_commit() const noexcept;
		std::uint64_t get_size_of_heap_reserve() const noexcept;
		std::uint64_t get_size_of_heap_commit() const noexcept;
		std::uint32_t get_loader_flags() const noexcept;
		std::uint32_t get_number_of_rva_and_sizes() const noexcept;

		nt make_nt(addresses_provider* addresses_provider);

	private:
		std::ifstream* _file_stream;

		headers::image_file_header _file_header;

		std::uint16_t _magic;
		std::uint8_t _major_linker_version;
		std::uint8_t _minor_linker_version;
		std::uint32_t _size_of_code;
		std::uint32_t _size_of_initialized_data;
		std::uint32_t _size_of_uninitialized_data;
		std::uint32_t _address_of_entry_point;
		std::uint32_t _base_of_code;
		std::optional<std::uint32_t> _base_of_data;
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
		std::uint32_t _size_of_image;
		std::uint32_t _size_of_headers;
		std::uint32_t _checksum;
		std::uint16_t _subsystem;
		std::uint16_t _dll_characteristics;
		std::uint64_t _size_of_stack_reserve;
		std::uint64_t _size_of_stack_commit;
		std::uint64_t _size_of_heap_reserve;
		std::uint64_t _size_of_heap_commit;
		std::uint32_t _loader_flags;
		std::uint32_t _number_of_rva_and_sizes;
		headers::image_data_directory _data_directory[headers::constants::nt_headers::number_of_directory_entries];

	private:
		void check_signature_validation();
		void read_file_header();
		void read_optional_header();
		void read_magic();
		bool is_nt32() const noexcept;
		bool is_nt64() const noexcept;

		template<class t>
		void read_optional_header()
		{
			t optional_header;

			this->_file_stream->read(reinterpret_cast<char*>(&optional_header), sizeof(optional_header));

			this->_major_linker_version = optional_header.major_linker_version;
			this->_minor_linker_version = optional_header.minor_linker_version;
			this->_size_of_code = optional_header.size_of_code;
			this->_size_of_initialized_data = optional_header.size_of_initialized_data;
			this->_size_of_uninitialized_data = optional_header.size_of_uninitialized_data;
			this->_address_of_entry_point = optional_header.address_of_entry_point;
			this->_base_of_code = optional_header.base_of_code;

			if constexpr (std::is_same_v<t, headers::image_optional_header32>)
			{
				this->_base_of_data = optional_header.base_of_data;
			}

			this->_image_base = optional_header.image_base;
			this->_section_alignment = optional_header.section_alignment;
			this->_file_alignment = optional_header.file_alignment;
			this->_major_operating_system_version = optional_header.major_operating_system_version;
			this->_minor_operating_system_version = optional_header.minor_operating_system_version;
			this->_major_image_version = optional_header.major_image_version;
			this->_minor_image_version = optional_header.minor_image_version;
			this->_major_subsystem_version = optional_header.major_subsystem_version;
			this->_minor_subsystem_version = optional_header.minor_subsystem_version;
			this->_win32_version_value = optional_header.win32_version_value;
			this->_size_of_image = optional_header.size_of_image;
			this->_size_of_headers = optional_header.size_of_headers;
			this->_checksum = optional_header.check_sum;
			this->_subsystem = optional_header.subsystem;
			this->_dll_characteristics = optional_header.dll_characteristics;
			this->_size_of_stack_reserve = optional_header.size_of_stack_reserve;
			this->_size_of_stack_commit = optional_header.size_of_stack_commit;
			this->_size_of_heap_reserve = optional_header.size_of_heap_reserve;
			this->_size_of_heap_commit = optional_header.size_of_heap_commit;
			this->_loader_flags = optional_header.loader_flags;
			this->_number_of_rva_and_sizes = optional_header.number_of_rva_and_sizes;

			std::memcpy(this->_data_directory, optional_header.data_directory, _number_of_rva_and_sizes * sizeof(headers::image_data_directory));
		}
	};
}

#endif