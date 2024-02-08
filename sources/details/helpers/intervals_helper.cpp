#include <ciso646>

#include <pe_library/details/helpers/intervals_helper.hpp>

bool pe_library::details::helpers::intervals_helper::is_value_between_interval(std::uint64_t value, std::uint64_t begin, std::uint64_t end) noexcept
{
	return (value >= begin) and (value <= end);
}

bool pe_library::details::helpers::intervals_helper::is_position_between_interval(std::uint64_t value, interval target_interval) noexcept
{
	return (value >= target_interval.get_position()) and (value <= target_interval.get_end_position());
}