#include <pe_library/details/containers/sections_container.hpp>

pe_library::details::sections_container::iterator pe_library::details::sections_container::begin()
{
	return this->_sections.begin();
}

pe_library::details::sections_container::iterator pe_library::details::sections_container::end()
{
	return this->_sections.end();
}

pe_library::details::sections_container::const_iterator pe_library::details::sections_container::cbegin() const
{
	return this->_sections.cbegin();
}

pe_library::details::sections_container::const_iterator pe_library::details::sections_container::cend() const
{
	return this->_sections.cend();
}

std::size_t pe_library::details::sections_container::size() const noexcept
{
	return this->_sections.size();
}

pe_library::details::sections_container::iterator pe_library::details::sections_container::find_section_with_name(std::string const& name)
{
	return std::find_if(this->_sections.begin(), this->_sections.end(), [&name](auto const& section) -> bool { return section.get_name() == name; });
}