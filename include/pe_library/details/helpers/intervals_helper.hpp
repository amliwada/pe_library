#ifndef PE_LIBRARY_INTERVALS_HELPER_HPP
#define PE_LIBRARY_INTERVALS_HELPER_HPP

#include <pe_library/interval.hpp>

namespace pe_library::details::helpers
{
	class intervals_helper
	{
	public:
		static bool is_value_between_interval(std::uint64_t value, std::uint64_t begin, std::uint64_t end) noexcept;
		static bool is_position_between_interval(std::uint64_t value, interval target_interval) noexcept;
	};
}

#endif