#ifndef PE_LIBRARY_SECTION_HEADER_CONSTANTS_HPP
#define PE_LIBRARY_SECTION_HEADER_CONSTANTS_HPP

#include <cstdint>
#include <cstdlib>

namespace pe_library::details::headers::constants::section_header
{
	constexpr std::uint32_t size_of_section_header{ 0x4550 };
	constexpr std::size_t size_of_short_name{ 8 };

	constexpr std::uint32_t type_no_pad{ 0x00000008 };
	constexpr std::uint32_t cnt_code{ 0x00000020 };
	constexpr std::uint32_t cnt_initialized_data{ 0x00000040 };
	constexpr std::uint32_t cnt_uninitialized_data{ 0x00000080 };
	constexpr std::uint32_t lnk_other{ 0x00000100 };
	constexpr std::uint32_t lnk_info{ 0x00000200 };
	constexpr std::uint32_t lnk_remove{ 0x00000800 };
	constexpr std::uint32_t lnk_comdat{ 0x00001000 };
	constexpr std::uint32_t no_defer_spec_exc{ 0x00004000 };
	constexpr std::uint32_t gprel{ 0x00008000 };
	constexpr std::uint32_t mem_fardata{ 0x00008000};
	constexpr std::uint32_t mem_purgeable{ 0x00020000};
	constexpr std::uint32_t mem_16bit{ 0x00020000};
	constexpr std::uint32_t mem_locked{ 0x00040000};
	constexpr std::uint32_t mem_preload{ 0x00080000};
	constexpr std::uint32_t align_1bytes{ 0x00100000 };
	constexpr std::uint32_t align_2bytes{ 0x00200000 };
	constexpr std::uint32_t align_4bytes{ 0x00300000 };
	constexpr std::uint32_t align_8bytes{ 0x00400000 };
	constexpr std::uint32_t align_16bytes{ 0x00500000 };
	constexpr std::uint32_t align_32bytes{ 0x00600000 };
	constexpr std::uint32_t align_64bytes{ 0x00700000 };
	constexpr std::uint32_t align_128bytes{ 0x00800000 };
	constexpr std::uint32_t align_256bytes{ 0x00900000 };
	constexpr std::uint32_t align_512bytes{ 0x00a00000 };
	constexpr std::uint32_t align_1024bytes{ 0x00b00000 };
	constexpr std::uint32_t align_2048bytes{ 0x00c00000 };
	constexpr std::uint32_t align_4096bytes{ 0x00d00000 };
	constexpr std::uint32_t align_8192bytes{ 0x00e00000 };
	constexpr std::uint32_t align_mask{ 0x00f00000 };
	constexpr std::uint32_t lnk_nreloc_ovfl{ 0x01000000 };
	constexpr std::uint32_t mem_discardable {0x02000000 };
	constexpr std::uint32_t mem_not_cached{ 0x04000000 };
	constexpr std::uint32_t mem_not_paged{ 0x08000000 };
	constexpr std::uint32_t mem_shared{ 0x10000000 };
	constexpr std::uint32_t mem_execute{ 0x20000000 };
	constexpr std::uint32_t mem_read{ 0x40000000 };
	constexpr std::uint32_t mem_write{ 0x80000000 };
}

#endif