#ifndef PE_LIBRARY_RICH_DATA_BUILDER_HPP
#define PE_LIBRARY_RICH_DATA_BUILDER_HPP

#include <pe_library/rich_data.hpp>
#include <pe_library/dos.hpp>

namespace pe_library::details::builders
{
	class rich_data_builder
	{
	public:
		void build(rich_data const& target_rich_data, dos const& target_dos);

		dos const& get_dos_with_rich_data() const noexcept;

	private:
		static inline constexpr auto begin_signature_size{ sizeof(rich_data::dans_signature) + sizeof(uint32_t) * 3 };
		static inline constexpr auto end_signature_size{ sizeof(rich_data::signature) + sizeof(rich_data::key_t) };

		static inline constexpr auto build_offset{ 0 };
		static inline constexpr auto product_id_offset{ sizeof(rich_data_entry::build_id_t) };
		static inline constexpr auto count_offset{ product_id_offset + sizeof(rich_data_entry::product_id_t) };

	private:
		rich_data const* _target_rich_data;
		dos _target_dos;

		bytecode _new_dos_stub;

		std::size_t _entries_size;
		std::uint64_t _rich_data_position;
		std::uint64_t _entry_position;

	private:
		void make_new_dos_stub();
		void insert_rich_data();

		template<class t>
		void write_entry_value_with_offset(t value, std::uint8_t offset)
		{
			helpers::bytecode_helper::write_value_to_position(&this->_new_dos_stub, value, this->_entry_position + offset);
		}
	};
}

#endif