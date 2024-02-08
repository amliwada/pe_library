#include <pe_library/file.hpp>
#include <pe_library/details/parsers/file_parser.hpp>
#include <pe_library/details/builders/file_builder.hpp>

pe_library::file pe_library::file::parse(std::filesystem::path const& path_to_file)
{
	details::parsers::file_parser file_parser;
	return file_parser.parse_file(path_to_file);
}

pe_library::dos const& pe_library::file::get_dos() const noexcept
{
	return this->_dos;
}

void pe_library::file::set_dos(dos&& value) noexcept
{
	this->_dos = std::move(value);
}

std::optional<pe_library::rich_data> const& pe_library::file::get_rich_data() const noexcept
{
	return this->_rich_data;
}

void pe_library::file::set_rich_data(rich_data&& value) noexcept
{
	this->_rich_data = std::move(value);
}

bool pe_library::file::has_rich_data() const noexcept
{
	return this->_rich_data.has_value();
}

pe_library::nt const& pe_library::file::get_nt() const noexcept
{
	return this->_nt;
}

void pe_library::file::set_nt(nt&& value) noexcept
{
	this->_nt = std::move(value);
}

pe_library::details::sections_container const& pe_library::file::get_sections() const noexcept
{
	return this->_sections;
}

void pe_library::file::set_sections(details::sections_container&& value) noexcept
{
	this->_sections = std::move(value);
}

pe_library::pe_version pe_library::file::get_version() const noexcept
{
	return this->_version;
}

void pe_library::file::set_version(pe_version value) noexcept
{
	this->_version = value;
}

pe_library::data_address const& pe_library::file::get_entry_point_address() const noexcept
{
	return this->get_nt().get_entry_point_address();
}

void pe_library::file::write_bytecode_to_address(bytecode const& value, data_address write_address)
{
	decltype(auto) section_iterator{ write_address.get_section_iterator() };
	decltype(auto) write_position{ write_address.get_data_interval_iterator()->get_position() };
	section_iterator->write_bytecode_to_position(value, write_position);
}

void pe_library::file::build(std::filesystem::path const& target_path)
{
	details::builders::file_builder file_builder;
	file_builder.build(*this, target_path);
}

pe_library::details::sections_container::iterator pe_library::file::find_section_with_name(std::string const& name)
{
	return this->_sections.find_section_with_name(name);
}