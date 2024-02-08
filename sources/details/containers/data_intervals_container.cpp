#include <ciso646>

#include <pe_library/details/containers/data_intervals_container.hpp>

pe_library::details::data_intervals_container::data_intervals_container(bytecode&& bytecode) noexcept
	: _bytecode{ std::move(bytecode) }
{ }

pe_library::bytecode const& pe_library::details::data_intervals_container::get_bytecode() const noexcept
{
	return this->_bytecode;
}

void pe_library::details::data_intervals_container::write_bytecode_to_position(bytecode const& value, const std::uint64_t position)
{
	std::memcpy(this->_bytecode.data() + position, value.data(), value.size());
}