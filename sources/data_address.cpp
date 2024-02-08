#include <pe_library/data_address.hpp>

pe_library::data_address::data_address(details::sections_container::iterator section_iterator, section::data_interval_iterator data_interval_iterator) noexcept
	: _section_iterator{ section_iterator }
	, _data_interval_iterator{ data_interval_iterator }
{ }

pe_library::details::sections_container::iterator const& pe_library::data_address::get_section_iterator() const noexcept
{
	return this->_section_iterator;
}

pe_library::section::data_interval_iterator const& pe_library::data_address::get_data_interval_iterator() const noexcept
{
	return this->_data_interval_iterator;
}