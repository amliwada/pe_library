#ifndef PE_LIBRARY_IMAGE_FILE_HEADER
#define PE_LIBRARY_IMAGE_FILE_HEADER

#include <cstdint>

namespace pe_library::details::headers
{
	struct image_file_header
	{
		std::uint16_t machine;
		std::uint16_t number_of_sections;
		std::uint32_t time_date_stamp;
		std::uint32_t pointer_to_symbol_table;
		std::uint32_t number_of_symbols;
		std::uint16_t size_of_optional_header;
		std::uint16_t characteristics;
	};
}

#endif