#include <pe_library/details/builders/dos_builder.hpp>
#include <pe_library/details/helpers/bytecode_helper.hpp>

pe_library::bytecode pe_library::details::builders::dos_builder::dos_to_bytecode(dos const& target_dos)
{
	this->_dos = &target_dos;
	this->_result = bytecode(this->_dos->get_size());

	this->write_header();
	this->write_stub();

	return this->_result;
}

void pe_library::details::builders::dos_builder::write_header() noexcept
{
	auto dos_headers{ this->_dos->get_header() };
	details::helpers::bytecode_helper::write_value_to_position(&this->_result, dos_headers, 0);
}

void pe_library::details::builders::dos_builder::write_stub() noexcept
{
	constexpr const auto size_of_header{ sizeof(headers::image_dos_header )};
	decltype(auto) dos_stub{ this->_dos->get_stub() };
	std::memcpy(this->_result.data() + size_of_header, dos_stub.data(), dos_stub.size());
}