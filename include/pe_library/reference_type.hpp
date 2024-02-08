#ifndef PE_LIBRARY_REFERENCE_TYPE_HPP
#define PE_LIBRARY_REFERENCE_TYPE_HPP

#include <cstdint>

namespace pe_library
{
	enum class reference_type
		: std::uint8_t
	{
		relative_virtual_address,
		virtual_address,
		relative
	};
}

#endif