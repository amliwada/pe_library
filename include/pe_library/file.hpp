#ifndef PE_LIBRARY_FILE_HPP
#define PE_LIBRARY_FILE_HPP

#include <filesystem>

#include <pe_library/dos.hpp>
#include <pe_library/rich_data.hpp>
#include <pe_library/nt.hpp>
#include <pe_library/details/containers/sections_container.hpp>
#include <pe_library/data_reference.hpp>
#include <pe_library/pe_version.hpp>

namespace pe_library
{
	class file
	{
	public:
		static file parse(std::filesystem::path const& path_to_file);

		dos const& get_dos() const noexcept;
		void set_dos(dos&& value) noexcept;
		
		std::optional<rich_data> const& get_rich_data() const noexcept;
		void set_rich_data(rich_data&& value) noexcept;

		bool has_rich_data() const noexcept;

		nt const& get_nt() const noexcept;
		void set_nt(nt&& value) noexcept;

		details::sections_container const& get_sections() const noexcept;
		void set_sections(details::sections_container&& value) noexcept;

		pe_version get_version() const noexcept;
		void set_version(pe_version value) noexcept;

		details::sections_container::iterator find_section_with_name(std::string const& name);

		template<class... ts>
		details::sections_container::iterator add_section(ts&&... vs)
		{
			return this->_sections.add_section(std::forward<ts>(vs)...);
		}

		void write_bytecode_to_address(bytecode const& value, data_address address);

		data_address const& get_entry_point_address() const noexcept;

		template<class t>
		t const* const read_value_from_address(data_address const& address)
		{
			decltype(auto) section_iterator{ address.get_section_iterator() };
			decltype(auto) read_position{ address.get_data_interval_iterator()->get_position() };
			return section_iterator->read_value_from_position<t>(read_position);
		}

		void build(std::filesystem::path const& target_path);

	private:
		dos _dos;
		std::optional<rich_data> _rich_data;
		nt _nt;
		details::sections_container _sections;
		pe_version _version;
	};
}

#endif