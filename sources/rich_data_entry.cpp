#include <ciso646>

#include <pe_library/rich_data_entry.hpp>

pe_library::rich_data_entry::rich_data_entry(product_id_t product_id, build_id_t build_id, count_t count) noexcept
	: _product_id{ product_id }
	, _build_id{ build_id }
	, _count{ count }
{ }

pe_library::rich_data_entry::product_id_t pe_library::rich_data_entry::get_product_id() const noexcept
{
	return this->_product_id;
}

void pe_library::rich_data_entry::set_product_id(product_id_t product_id) noexcept
{
	this->_product_id = product_id;
}

pe_library::rich_data_entry::build_id_t pe_library::rich_data_entry::get_build_id() const noexcept
{
	return this->_build_id;
}

void pe_library::rich_data_entry::set_build_id(build_id_t build_id) noexcept
{
	this->_build_id = build_id;
}

pe_library::rich_data_entry::count_t pe_library::rich_data_entry::get_count() const noexcept
{
	return this->_count;
}

void pe_library::rich_data_entry::set_count(count_t count) noexcept
{
	this->_count = count;
}

bool pe_library::rich_data_entry::operator==(rich_data_entry const& other_entry) const noexcept
{
	auto is_same_product_id{ this->get_product_id() == other_entry.get_product_id()};
	auto is_same_build_id{ this->get_build_id() == other_entry.get_build_id()};
	auto is_same_count_id{ this->get_count() == other_entry.get_count( )};
	return is_same_product_id and is_same_build_id and is_same_product_id;
}