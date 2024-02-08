#include <pe_library/details/builders/nt_builder.hpp>
#include <pe_library/details/headers/image_nt_headers32.hpp>
#include <pe_library/details/headers/image_nt_headers64.hpp>

std::size_t pe_library::details::builders::nt_builder::get_size_of_nt_headers(file const& target_file) const noexcept
{
	if (target_file.get_version() == pe_version::pe_plus)
	{
		return sizeof(headers::image_nt_headers64);
	}
	else
	{
		return sizeof(headers::image_nt_headers32);
	}
}

pe_library::bytecode pe_library::details::builders::nt_builder::get_headers_bytecode(file const& target_file, sections_builder const& sections, std::size_t size_of_headers)
{
	this->_target_file = &target_file;
	this->_size_of_headers = size_of_headers;
	this->_sections = &sections;

	if (target_file.get_version() == pe_version::pe_plus)
	{
		this->build_nt<headers::image_nt_headers64>();
	}
	else
	{
		this->build_nt<headers::image_nt_headers32>();
	}

	return this->_headers_bytecode;
}