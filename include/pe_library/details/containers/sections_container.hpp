#ifndef PE_LIBRARY_SECTIONS_CONTAINER_HPP
#define PE_LIBRARY_SECTIONS_CONTAINER_HPP

#include <list>
#include <iterator>

#include <pe_library/section.hpp>

namespace pe_library::details
{
	class sections_container
	{
	public:
		using iterator = std::list<section>::iterator;
		using const_iterator = std::list<section>::const_iterator;

		iterator begin() noexcept;
		iterator end() noexcept;

		const_iterator cbegin() const noexcept;
		const_iterator cend() const noexcept;

		section const& front() const noexcept;
		section& front() noexcept;

		section const& back() const noexcept;
		section& back() noexcept;

		template<class... ts>
		decltype(auto) add_section(ts&&... vs)
		{
			return _sections.emplace(this->_sections.cend(), std::forward<ts>(vs)...);
		}

		std::size_t size() const noexcept;

		iterator find_section_with_name(std::string const& name);

	private:
		std::list<section> _sections;
	};
}

#endif