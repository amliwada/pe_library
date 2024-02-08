#ifndef PE_LIBRARY_IMAGE_SECTION_HEADER_HPP
#define PE_LIBRARY_IMAGE_SECTION_HEADER_HPP

#include <pe_library/details/constants/section_header_constants.hpp>

namespace pe_library::details::headers
{
	struct image_section_header
	{
        char name[constants::section_header::size_of_short_name];
        std::uint32_t virtual_size;
        std::uint32_t virtual_address;
        std::uint32_t size_of_raw_data;
        std::uint32_t pointer_to_raw_data;
        std::uint32_t pointer_to_relocations;
        std::uint32_t pointer_to_linenumbers;
        std::uint16_t number_of_relocations;
        std::uint16_t number_of_linenumbers;
        std::uint32_t characteristics;
	};
}

#endif