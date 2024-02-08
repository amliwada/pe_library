#ifndef PE_LIBRARY_DATA_REFERENCE_HPP
#define PE_LIBRARY_DATA_REFERENCE_HPP
 
#include <pe_library/data_address.hpp>
#include <pe_library/reference_type.hpp>

namespace pe_library
{
	class data_reference
	{
	public:
		data_reference(data_address reference_address, data_address target_data_address, reference_type type);

		data_address const& get_reference_address() const noexcept;
		data_address const& get_target_data_address() const noexcept;
		reference_type get_type() const noexcept;

	private:
		data_address _reference_address;
		data_address _target_data_address;
		reference_type _type;
	};
}

#endif