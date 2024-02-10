#include <ciso646>

#include <pe_library/section.hpp>

pe_library::section::section(std::string&& name, bytecode&& section_bytecode) noexcept
	: data_intervals_container{ std::move(section_bytecode) }
	, _name{ std::move(name) }
	, _virtual_size{ 0 }
{
	this->set_readable();
}

void pe_library::section::set_name(std::string&& name) noexcept
{
	this->_name = std::move(name);
}

std::string const& pe_library::section::get_name() const noexcept
{
	return this->_name;
}

std::uint32_t pe_library::section::get_characteristics() const noexcept
{
	return this->_characteristics;
}

void pe_library::section::set_characteristics(std::uint32_t value)
{
	this->_characteristics = value;
}

std::uint32_t pe_library::section::get_virtual_size() const noexcept
{
	return this->_virtual_size;
}

void pe_library::section::set_virtual_size(std::uint32_t value) noexcept
{
	this->_virtual_size = value;
}

void pe_library::section::set_readable() noexcept
{
	this->set_characteristic(details::headers::constants::section_header::mem_read);
}

void pe_library::section::unset_readable() noexcept
{
	this->unset_characteristic(details::headers::constants::section_header::mem_read);
}

bool pe_library::section::is_readable() const noexcept
{
	return this->has_characteristic(details::headers::constants::section_header::mem_read);
}

void pe_library::section::set_writeable() noexcept
{
	this->set_characteristic(details::headers::constants::section_header::mem_write);
}

void pe_library::section::unset_writeable() noexcept
{
	this->unset_characteristic(details::headers::constants::section_header::mem_write);
}

bool pe_library::section::is_writeable() const noexcept
{
	return this->has_characteristic(details::headers::constants::section_header::mem_write);
}

void pe_library::section::set_executable() noexcept
{
	this->set_characteristic(details::headers::constants::section_header::mem_execute);
}

void pe_library::section::unset_executable() noexcept
{
	this->unset_characteristic(details::headers::constants::section_header::mem_execute);
}

bool pe_library::section::is_executable() const noexcept
{
	return this->has_characteristic(details::headers::constants::section_header::mem_execute);
}

void pe_library::section::set_shared() noexcept
{
	this->set_characteristic(details::headers::constants::section_header::mem_shared);
}

void pe_library::section::unset_shared() noexcept
{
	this->unset_characteristic(details::headers::constants::section_header::mem_shared);
}

bool pe_library::section::is_shared() const noexcept
{
	return this->has_characteristic(details::headers::constants::section_header::mem_shared);
}

void pe_library::section::set_discardable() noexcept
{
	this->set_characteristic(details::headers::constants::section_header::mem_discardable);
}

void pe_library::section::unset_discardable() noexcept
{
	this->unset_characteristic(details::headers::constants::section_header::mem_discardable);
}

bool pe_library::section::is_discardable() const noexcept
{
	return this->has_characteristic(details::headers::constants::section_header::mem_discardable);
}

void pe_library::section::set_characteristic(std::uint32_t value) noexcept
{
	this->_characteristics or_eq value;
}

void pe_library::section::unset_characteristic(std::uint32_t value) noexcept
{
	this->_characteristics and_eq compl value;
}

bool pe_library::section::has_characteristic(std::uint32_t value) const noexcept
{
	return this->_characteristics and value;
}