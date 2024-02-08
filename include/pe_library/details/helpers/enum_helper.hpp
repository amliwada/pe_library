#ifndef PE_LIBRARY_ENUM_HELPER_HPP
#define PE_LIBRARY_ENUM_HELPER_HPP

#include <type_traits>

namespace pe_library::details
{
	class enum_helper
	{
	public:
		template<class t>
		static constexpr int enum_to_int(t value) noexcept
		{
			return static_cast<std::underlying_type_t<t>>(value);
		}
	};
}

#endif