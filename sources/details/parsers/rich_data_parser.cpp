#include <ciso646>

#include <pe_library/details/parsers/rich_data_parser.hpp>
#include <pe_library/details/helpers/bytecode_helper.hpp>

void pe_library::details::parsers::rich_data_parser::parse_rich_data_in_dos(dos const& target_dos)
{
	decltype(auto) dos_stub{ target_dos.get_stub() };

	if (dos_stub.empty())
	{
		return;
	}

	std::optional<std::size_t> rich_signature_position{ std::nullopt };

	for (std::size_t position{ 0 }; position < dos_stub.size(); position += sizeof(rich_data::signature))
	{
		if (*details::helpers::bytecode_helper::read_value_from_position<decltype(rich_data::signature)>(dos_stub, position) == rich_data::signature)
		{
			rich_signature_position = position;
			break;
		}
	}

	if (!rich_signature_position)
	{
		return;
	}

	auto rich_key{ *details::helpers::bytecode_helper::read_value_from_position<rich_data::key_t>(dos_stub, rich_signature_position.value() + sizeof(std::uint32_t)) };

	std::optional<std::size_t> dans_signature_position{ std::nullopt };

	for (std::size_t position{ rich_signature_position.value() }; position > 0; position -= sizeof(rich_data::dans_signature))
	{
		if ((*details::helpers::bytecode_helper::read_value_from_position<decltype(rich_data::dans_signature)>(dos_stub, position) xor rich_key) == rich_data::dans_signature)
		{
			dans_signature_position = position;
			break;
		}
	}

	if (!dans_signature_position)
	{
		return;
	}

	this->_rich_data = rich_data{ rich_key };

	auto rich_data_position{ *dans_signature_position };

	this->_rich_data_position = rich_data_position;

	std::size_t position{ rich_data_position };

	position += sizeof(rich_data::dans_signature) + (sizeof(std::uint32_t) * 3);

	while (position < rich_signature_position.value())
	{
		auto product_build{ *details::helpers::bytecode_helper::read_value_from_position<std::uint32_t>(dos_stub, position) xor rich_key };
		rich_data_entry::product_id_t product_id{ static_cast<rich_data_entry::product_id_t>(product_build >> 16) };
		rich_data_entry::build_id_t build_id{ static_cast<rich_data_entry::build_id_t>(product_build bitand 0xffff) };
		position += sizeof(product_build);

		auto count{ *details::helpers::bytecode_helper::read_value_from_position<rich_data_entry::count_t>(dos_stub, position) xor rich_key };
		position += sizeof(count);

		this->_rich_data->add_entry(rich_data_entry{ product_id, build_id, count });
	}
}

std::optional<pe_library::rich_data> const& pe_library::details::parsers::rich_data_parser::get_parsed_rich_data() const noexcept
{
	return this->_rich_data;
}

std::size_t pe_library::details::parsers::rich_data_parser::get_rich_data_position() const noexcept
{
	return this->_rich_data_position;
}