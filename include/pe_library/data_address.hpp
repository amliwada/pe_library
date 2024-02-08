#ifndef PE_LIBRARY_DATA_ADDRESS_HPP
#define PE_LIBRARY_DATA_ADDRESS_HPP

#include <pe_library/details/containers/sections_container.hpp>
#include <pe_library/interval.hpp>

namespace pe_library
{
	class data_address
	{
	public:
		data_address() noexcept = default;
		data_address(details::sections_container::iterator section_iterator, section::data_interval_iterator data_interval_iterator) noexcept;

		details::sections_container::iterator const& get_section_iterator() const noexcept;
		section::data_interval_iterator const& get_data_interval_iterator() const noexcept;

	private:
		details::sections_container::iterator _section_iterator;
		section::data_interval_iterator _data_interval_iterator;
	};
}

#endif