#include <pe_library/details/providers/addresses_provider.hpp>
#include <pe_library/details/helpers/bytes_helper.hpp>

pe_library::details::addresses_provider::addresses_provider(std::uint64_t image_base, parsers::sections_parser* sections_parser)
	: _image_base{ image_base }
	, _sections_parser{ sections_parser }
{ }

std::optional<pe_library::data_address> pe_library::details::addresses_provider::imm_to_data_address(std::uint64_t imm) const noexcept
{
	if (imm == 0)
	{
		return std::nullopt;
	}

	imm = helpers::bytes_helper::remove_int_in_value(this->_image_base, imm);

	return this->_sections_parser->rva_to_data_address(imm);
}