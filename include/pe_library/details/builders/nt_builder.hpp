#ifndef PE_LIBRARY_NT_BUILDER_HPP
#define PE_LIBRARY_NT_BUILDER_HPP

#include <fstream>

#include <pe_library/file.hpp>
#include <pe_library/details/builders/sections_builder.hpp>
#include <pe_library/details/headers/image_nt_headers32.hpp>
#include <pe_library/details/headers/image_nt_headers64.hpp>
#include <pe_library/details/helpers/bytes_helper.hpp>

namespace pe_library::details::builders
{
	class nt_builder
	{
	public:
		std::size_t get_size_of_nt_headers(file const& target_file) const noexcept;
		bytecode get_headers_bytecode(file const& target_file, sections_builder const& sections, std::size_t size_of_headers);

	private:
		std::size_t _size_of_headers;
		sections_builder const* _sections;
		file const* _target_file;

		bytecode _headers_bytecode;

	private:
		template<class headers_t>
		headers_t make_nt_headers()
		{
			headers_t headers{ 0 };

			decltype(auto) nt{ this->_target_file->get_nt() };

			headers.signature = IMAGE_NT_SIGNATURE;

			headers.file_header.machine = nt.get_machine();
			headers.file_header.number_of_sections = static_cast<std::uint16_t>(this->_target_file->get_sections().size());
			headers.file_header.time_date_stamp = nt.get_time_date_stamp();

			if constexpr (std::is_same_v<headers_t, headers::image_nt_headers32>)
			{
				headers.file_header.size_of_optional_header = sizeof(headers::image_optional_header32);
			}
			else if constexpr (std::is_same_v<headers_t, headers::image_nt_headers64>)
			{
				headers.file_header.size_of_optional_header = sizeof(headers::image_optional_header64);
			}

			headers.file_header.characteristics = nt.get_characteristics();
			headers.optional_header.address_of_entry_point = static_cast<std::uint32_t>(this->_sections->data_address_to_imm(nt.get_entry_point_address(), reference_type::relative_virtual_address));
			headers.optional_header.magic = nt.get_magic();
			headers.optional_header.major_linker_version = nt.get_major_linker_version();
			headers.optional_header.minor_linker_version = nt.get_minor_linker_version();
			headers.optional_header.size_of_code = static_cast<std::uint32_t>(this->_sections->get_size_of_code());
			headers.optional_header.size_of_initialized_data = static_cast<std::uint32_t>(this->_sections->get_size_of_initialized_data());
			headers.optional_header.size_of_uninitialized_data = static_cast<std::uint32_t>(this->_sections->get_size_of_uninitialized_data());

			headers.optional_header.base_of_code = static_cast<std::uint32_t>(this->_sections->get_section_virtual_address(nt.get_code_section()));

			if constexpr (std::is_same_v<headers_t, headers::image_nt_headers32>)
			{
				headers.optional_header.base_of_data = static_cast<std::uint32_t>(this->_sections->get_section_virtual_address(nt.get_data_section()));
			}

			if constexpr (std::is_same_v<headers_t, headers::image_nt_headers32>)
			{
				headers.optional_header.image_base = static_cast<std::uint32_t>(nt.get_image_base());
			}
			else
			{
				headers.optional_header.image_base = nt.get_image_base();
			}
			
			headers.optional_header.section_alignment = nt.get_section_alignment();
			headers.optional_header.file_alignment = nt.get_file_alignment();
			headers.optional_header.major_operating_system_version = nt.get_major_operating_system_version();
			headers.optional_header.minor_operating_system_version = nt.get_minor_operating_system_version();
			headers.optional_header.major_image_version = nt.get_major_image_version();
			headers.optional_header.minor_image_version = nt.get_minor_image_version();
			headers.optional_header.major_subsystem_version = nt.get_major_subsystem_version();
			headers.optional_header.minor_subsystem_version = nt.get_minor_subsystem_version();
			headers.optional_header.win32_version_value = nt.get_win32_version_value();
			headers.optional_header.size_of_image = static_cast<std::uint32_t>(this->_sections->get_size_of_image());
			headers.optional_header.size_of_headers = static_cast<std::uint32_t>(this->_size_of_headers);
			headers.optional_header.check_sum = nt.get_checksum();
			headers.optional_header.subsystem = nt.get_subsystem();
			headers.optional_header.dll_characteristics = nt.get_dll_characteristics();

			if constexpr (std::is_same_v<headers_t, headers::image_nt_headers32>)
			{
				headers.optional_header.size_of_stack_reserve = static_cast<std::uint32_t>(nt.get_size_of_stack_reserve());
				headers.optional_header.size_of_stack_commit = static_cast<std::uint32_t>(nt.get_size_of_stack_commit());
				headers.optional_header.size_of_heap_reserve = static_cast<std::uint32_t>(nt.get_size_of_heap_reserve());
				headers.optional_header.size_of_heap_commit = static_cast<std::uint32_t>(nt.get_size_of_heap_commit());
			}
			else
			{
				headers.optional_header.size_of_stack_reserve = nt.get_size_of_stack_reserve();
				headers.optional_header.size_of_stack_commit = nt.get_size_of_stack_commit();
				headers.optional_header.size_of_heap_reserve = nt.get_size_of_heap_reserve();
				headers.optional_header.size_of_heap_commit = nt.get_size_of_heap_commit();
			}
			
			headers.optional_header.loader_flags = nt.get_loader_flags();
			headers.optional_header.number_of_rva_and_sizes = headers::constants::nt_headers::number_of_directory_entries;

			decltype(auto) data_directory{ nt.get_data_directory() };

			for (int i{ 0 }; i < details::headers::constants::nt_headers::number_of_directory_entries; ++i)
			{
				decltype(auto) entry_address{ data_directory[i] };

				if (entry_address == std::nullopt)
				{
					continue;
				}

				details::headers::image_data_directory data_entry
				{
					static_cast<std::uint32_t>(this->_sections->data_address_to_imm(entry_address.value(), reference_type::relative_virtual_address)),
					static_cast<std::uint32_t>(entry_address->get_data_interval_iterator()->get_size())
				};

				headers.optional_header.data_directory[i] = data_entry;
			}

			return headers;
		}

		template<class headers_t>
		void build_nt() noexcept
		{
			auto headers{ this->make_nt_headers<headers_t>() };
			auto headers_begin{ reinterpret_cast<char const* const>(&headers) };
			std::copy(headers_begin, headers_begin + sizeof(headers), std::back_inserter(this->_headers_bytecode));
		}
	};
}

#endif