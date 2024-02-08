#ifndef PE_LIBRARY_BYTES_HELPER_HPP
#define PE_LIBRARY_BYTES_HELPER_HPP

#include <cstdint>

namespace pe_library::details::helpers
{
	class bytes_helper
	{
	public:
		static std::uint64_t get_bits(std::uint64_t value, std::uint64_t bits_offset, std::uint64_t bits_count) noexcept;

		static std::uint64_t has_bits_in_value(std::uint64_t bits, std::uint64_t value) noexcept;

		static std::uint64_t align_down(std::uint64_t val, std::uint64_t align) noexcept;
		static std::uint64_t align_up(std::uint64_t val, std::uint64_t align) noexcept;

		static std::uint64_t remove_int_in_value(std::uint64_t i, std::uint64_t value) noexcept;
	};
}

#endif