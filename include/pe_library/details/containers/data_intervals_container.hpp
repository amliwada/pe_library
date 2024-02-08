#ifndef PE_LIBRARY_DATA_INTERVALS_CONTAINER_HPP
#define PE_LIBRARY_DATA_INTERVALS_CONTAINER_HPP

#include <list>

#include <pe_library/details/helpers/bytecode_helper.hpp>
#include <pe_library/interval.hpp>

namespace pe_library::details
{
	class data_intervals_container
	{
	public:
		using data_interval_iterator = std::list<interval>::iterator;
		using data_interval_const_iterator = std::list<interval>::const_iterator;

		data_intervals_container(bytecode&& bytecode) noexcept;

		bytecode const& get_bytecode() const noexcept;

		template<class... ts>
		decltype(auto) add_data_interval(ts&&... vs)
		{
			return _data_intervals.insert(this->_data_intervals.cend(), std::forward<ts>(vs)...);
		}

		template<class t>
		t const* const read_value_from_position(std::uint64_t position)
		{
			return details::helpers::bytecode_helper::read_value_from_position<t>(this->_bytecode, position);
		}

		void write_bytecode_to_position(bytecode const& value, const std::uint64_t position);

		template<class t>
		void write_value_to_position(const t value, const std::uint64_t position)
		{
			return details::helpers::bytecode_helper::write_value_to_position(&this->_bytecode, value, position);
		}

	private:
		bytecode _bytecode;

		std::list<interval> _data_intervals;
	};
}

#endif