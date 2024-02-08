#include <exception>

#include <pe_library/interval.hpp>

pe_library::interval::interval() noexcept
	: _position{ 0 }
	, _size{ 1 }
{ }

pe_library::interval::interval(std::uint64_t position, std::uint64_t size) noexcept
	: _position{ position }
	, _size{ size }
{ }

std::uint64_t pe_library::interval::get_position() const noexcept
{
	return this->_position;
}

void pe_library::interval::set_position(std::uint64_t value) noexcept
{
	this->_position = value;
}

std::uint64_t pe_library::interval::get_size() const noexcept
{
	return this->_size;
}

void pe_library::interval::set_size(std::uint64_t value)
{
	if (value < 1)
	{
		throw std::exception{ "interval size cannot be less than 1" };
	}

	this->_size = value;
}

std::uint64_t pe_library::interval::get_end_position() const noexcept
{
	return this->_position + this->_size;
}