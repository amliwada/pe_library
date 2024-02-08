#ifndef PE_LIBRARY_IMAGE_NT_HEADERS32_HPP
#define PE_LIBRARY_IMAGE_NT_HEADERS32_HPP

#include <pe_library/details/headers/image_file_header.hpp>
#include <pe_library/details/headers/image_optional_header32.hpp>

namespace pe_library::details::headers
{
	struct image_nt_headers32
	{
		std::uint32_t signature;
		image_file_header file_header;
		image_optional_header32 optional_header;
	};
}

#endif