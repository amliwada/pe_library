#include <limits>
#include <ciso646>

#include <pe_library/details/helpers/bytes_helper.hpp>

std::size_t pe_library::details::helpers::bytes_helper::get_bits(std::size_t value, std::size_t bits_offset, std::size_t bits_count) noexcept
{
	value <<= (std::numeric_limits<std::uint32_t>::digits - bits_count - bits_offset);
	value >>= (std::numeric_limits<std::uint32_t>::digits - bits_count);
	return value;
}

std::size_t pe_library::details::helpers::bytes_helper::has_bits_in_value(std::size_t bits, std::size_t value) noexcept
{
	return (value - (value bitand (compl bits))) == bits;
}

std::size_t pe_library::details::helpers::bytes_helper::align_down(std::size_t val, std::size_t align) noexcept
{
	return val bitand (compl (align - 1));
}

std::size_t pe_library::details::helpers::bytes_helper::align_up(std::size_t val, std::size_t align) noexcept
{
	auto temp{ align_down(val, align) };
	return temp not_eq val ? temp + align : temp;
}

std::uint64_t pe_library::details::helpers::bytes_helper::remove_int_in_value(std::uint64_t i, std::uint64_t value) noexcept
{
	return has_bits_in_value(i, value) ? value - i : value;
}