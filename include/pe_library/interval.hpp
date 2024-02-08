#ifndef PE_LIBRARY_INTERVAL_HPP
#define PE_LIBRARY_INTERVAL_HPP

#include <cstdint>

namespace pe_library
{
	class interval
	{
	public:
		interval() noexcept;
		interval(std::uint64_t position, std::uint64_t size) noexcept;

		std::uint64_t get_position() const noexcept;
		void set_position(std::uint64_t value) noexcept;

		std::uint64_t get_size() const noexcept;
		void set_size(std::uint64_t value);

		std::uint64_t get_end_position() const noexcept;

	private:
		std::uint64_t _position;
		std::uint64_t _size;
	};
}

#endif