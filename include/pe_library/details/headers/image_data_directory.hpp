#ifndef PE_LIBRARY_DATA_DIRECTORY
#define PE_LIBRARY_DATA_DIRECTORY

#include <cstdint>

namespace pe_library::details::headers
{
	struct image_data_directory
	{
		std::uint32_t virtual_address;
		std::uint32_t size;
	};
}

#endif