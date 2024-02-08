#ifndef PE_LIBRARY_RICH_DATA_ENTRY_HPP
#define PE_LIBRARY_RICH_DATA_ENTRY_HPP

#include <cstdint>

namespace pe_library
{
	class rich_data_entry
	{
	public:
		using product_id_t = std::uint16_t;
		using build_id_t = std::uint16_t;
		using count_t = std::uint32_t;

		rich_data_entry(product_id_t product_id, build_id_t build_id, count_t count) noexcept;

		product_id_t get_product_id() const noexcept;
		void set_product_id(product_id_t value) noexcept;

		build_id_t get_build_id() const noexcept;
		void set_build_id(build_id_t value) noexcept;

		count_t get_count() const noexcept;
		void set_count(count_t value) noexcept;

		bool operator==(rich_data_entry const& other_entry) const noexcept;

	private:
		product_id_t _product_id;
		build_id_t _build_id;
		count_t _count;
	};
}

#endif