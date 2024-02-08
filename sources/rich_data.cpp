#include <pe_library/rich_data.hpp>

pe_library::rich_data::rich_data(key_t key) noexcept
	: _key{ key }
{ }

void pe_library::rich_data::set_key(key_t value) noexcept
{
	this->_key = value;
}

pe_library::rich_data::key_t pe_library::rich_data::get_key() const noexcept
{
	return this->_key;
}

std::vector<pe_library::rich_data_entry> const& pe_library::rich_data::get_entries() const noexcept
{
	return this->_entries;
}

void pe_library::rich_data::add_entry(rich_data_entry&& value) noexcept
{
	this->_entries.emplace_back(std::move(value));
}