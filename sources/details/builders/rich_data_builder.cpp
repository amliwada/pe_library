#include <ciso646>

#include <pe_library/details/builders/rich_data_builder.hpp>
#include <pe_library/details/helpers/bytes_helper.hpp>
#include <pe_library/details/helpers/bytecode_helper.hpp>

void pe_library::details::builders::rich_data_builder::build(rich_data const& target_rich_data, dos const& target_dos)
{
	if (target_rich_data.get_entries().empty())
	{
		return;
	}

	this->_target_rich_data = &target_rich_data;
	this->_target_dos = target_dos;

	this->make_new_dos_stub();
	this->insert_rich_data();
}

void pe_library::details::builders::rich_data_builder::make_new_dos_stub()
{
	this->_new_dos_stub = this->_target_dos.get_stub();
	this->_new_dos_stub.resize(helpers::bytes_helper::align_up(this->_new_dos_stub.size(), 0x10));
}

void pe_library::details::builders::rich_data_builder::insert_rich_data()
{
	this->_rich_data_position = this->_new_dos_stub.size();
	this->_entry_position = _rich_data_position + this->begin_signature_size;

	decltype(auto) entries{ this->_target_rich_data->get_entries() };

	this->_entries_size = entries.size() * sizeof(rich_data_entry);
	auto rich_data_size{ this->begin_signature_size + this->_entries_size + this->end_signature_size };
	this->_new_dos_stub.resize(_new_dos_stub.size() + rich_data_size);

	helpers::bytecode_helper::write_value_to_position(&this->_new_dos_stub, rich_data::dans_signature, this->_rich_data_position);

	for (std::size_t i{ 0 }; i < entries.size(); ++i)
	{
		decltype(auto) entry{ entries.at(i) };

		this->write_entry_value_with_offset(entry.get_build_id(), build_offset);
		this->write_entry_value_with_offset(entry.get_product_id(), product_id_offset);
		this->write_entry_value_with_offset(entry.get_count(), count_offset);

		this->_entry_position += sizeof(rich_data_entry);
	}

	for (auto xor_address{ this->_rich_data_position }; xor_address not_eq this->_new_dos_stub.size() - this->end_signature_size; xor_address += sizeof(rich_data::key_t))
	{
		auto data{ *helpers::bytecode_helper::read_value_from_position<rich_data::key_t>(this->_new_dos_stub, xor_address) };
		helpers::bytecode_helper::write_value_to_position(&this->_new_dos_stub, data xor_eq this->_target_rich_data->get_key(), xor_address);
	}

	helpers::bytecode_helper::write_value_to_position(&this->_new_dos_stub, rich_data::signature, this->_entry_position);
	helpers::bytecode_helper::write_value_to_position(&this->_new_dos_stub, this->_target_rich_data->get_key(), this->_entry_position + sizeof(rich_data::signature));
	this->_target_dos.set_stub(std::move(this->_new_dos_stub));
}

pe_library::dos const& pe_library::details::builders::rich_data_builder::get_dos_with_rich_data() const noexcept
{
	return this->_target_dos;
}