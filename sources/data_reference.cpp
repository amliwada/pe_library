#include <pe_library/data_reference.hpp>

pe_library::data_reference::data_reference(data_address reference_address, data_address target_data_address, reference_type type)
	: _reference_address{ reference_address }
	, _target_data_address{ target_data_address }
	, _type{ type }
{ }

pe_library::data_address const& pe_library::data_reference::get_reference_address() const noexcept
{
	return this->_reference_address;
}

pe_library::data_address const& pe_library::data_reference::get_target_data_address() const noexcept
{
	return this->_target_data_address;
}

pe_library::reference_type pe_library::data_reference::get_type() const noexcept
{
	return this->_type;
}