#ifndef PE_LIBRARY_NT_CONSTANTS_HPP
#define PE_LIBRARY_NT_CONSTANTS_HPP

#include <ciso646>
#include <cstdlib>
#include <windows.h>
namespace pe_library::details::headers::constants::nt_headers
{
	constexpr std::uint32_t nt_signature{ 0x4550 };
	constexpr std::size_t number_of_directory_entries{ 16 };
	constexpr std::uint16_t optional_header_magic_32{ 0x10b };
	constexpr std::uint16_t optional_header_magic_64{ 0x20b };

	constexpr std::uint16_t directory_entry_export{ 0 };
	constexpr std::uint16_t directory_entry_import{ 1 };
	constexpr std::uint16_t directory_entry_resource{ 2 };
	constexpr std::uint16_t directory_entry_exception{ 3 };
	constexpr std::uint16_t directory_entry_security{ 4 };
	constexpr std::uint16_t directory_entry_basereloc{ 5 };
	constexpr std::uint16_t directory_entry_debug{ 6 };
	constexpr std::uint16_t directory_entry_architecture{ 7 };
	constexpr std::uint16_t directory_entry_globalptr{ 8 };
	constexpr std::uint16_t directory_entry_tls{ 9 };
	constexpr std::uint16_t directory_entry_load_config{ 10 };
	constexpr std::uint16_t directory_entry_bound_import{ 11 };
	constexpr std::uint16_t directory_entry_iat{ 12 };
	constexpr std::uint16_t directory_entry_delay_import{ 13 };
	constexpr std::uint16_t directory_entry_com_descriptor{ 14 };

}

#endif