#ifndef PE_LIBRARY_SECTION_HPP
#define PE_LIBRARY_SECTION_HPP

#include <string>

#include <pe_library/details/constants/section_header_constants.hpp>
#include <pe_library/details/containers/data_intervals_container.hpp>

namespace pe_library
{
	class section
		: public details::data_intervals_container
	{
	public:
		section(std::string&& name, bytecode&& section_bytecode) noexcept;

		void set_name(std::string&& name) noexcept;
		std::string const& get_name() const noexcept;

		std::uint32_t get_characteristics() const noexcept;
		void set_characteristics(std::uint32_t value);

		std::uint32_t get_virtual_size() const noexcept;
		void set_virtual_size(std::uint32_t value) noexcept;

		void set_readable() noexcept;
		void unset_readable() noexcept;
		bool is_readable() const noexcept;

		void set_writeable() noexcept;
		void unset_writeable() noexcept;
		bool is_writeable() const noexcept;

		void set_executable() noexcept;
		void unset_executable() noexcept;
		bool is_executable() const noexcept;

		void set_shared() noexcept;
		void unset_shared() noexcept;
		bool is_shared() const noexcept;

		void set_discardable() noexcept;
		void unset_discardable() noexcept;
		bool is_discardable() const noexcept;

	private:
		std::string _name;
		std::uint32_t _characteristics;
		std::uint32_t _virtual_size;

	private:
		void set_characteristic(std::uint32_t value) noexcept;
		void unset_characteristic(std::uint32_t value) noexcept;
		bool has_characteristic(std::uint32_t value) const noexcept;
	};
}

#endif