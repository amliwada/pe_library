#include <pe_library/details/containers/sections_container.hpp>

pe_library::details::sections_container::iterator pe_library::details::sections_container::begin() noexcept
{
	return this->_sections.begin();
}

pe_library::details::sections_container::iterator pe_library::details::sections_container::end() noexcept
{
	return this->_sections.end();
}

pe_library::details::sections_container::const_iterator pe_library::details::sections_container::cbegin() const noexcept
{
	return this->_sections.cbegin();
}

pe_library::details::sections_container::const_iterator pe_library::details::sections_container::cend() const noexcept
{
	return this->_sections.cend();
}

pe_library::section const& pe_library::details::sections_container::front() const noexcept
{
	return this->_sections.front();
}

pe_library::section& pe_library::details::sections_container::front() noexcept
{
	return this->_sections.front();
}

pe_library::section const& pe_library::details::sections_container::back() const noexcept
{
	return this->_sections.back();
}

pe_library::section& pe_library::details::sections_container::back() noexcept
{
	return this->_sections.back();
}

std::size_t pe_library::details::sections_container::size() const noexcept
{
	return this->_sections.size();
}

pe_library::details::sections_container::iterator pe_library::details::sections_container::find_section_with_name(std::string const& name)
{
	return std::find_if(this->_sections.begin(), this->_sections.end(), [&name](auto const& section) -> bool { return section.get_name() == name; });
}