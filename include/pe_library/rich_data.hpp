#ifndef PE_LIBRARY_RICH_HPP
#define PE_LIBRARY_RICH_HPP

#include <optional>

#include <pe_library/dos.hpp>
#include <pe_library/rich_data_entry.hpp>

namespace pe_library
{
	class rich_data
	{
	public:
		using key_t = std::uint32_t;

		static constexpr const std::uint32_t signature{ 0x68636952 };
		static constexpr const std::uint32_t dans_signature{ 0x536e6144 };

		rich_data(key_t key) noexcept;

		key_t get_key() const noexcept;
		void set_key(key_t value) noexcept;

		std::vector<rich_data_entry> const& get_entries() const noexcept;
		void add_entry(rich_data_entry&& value) noexcept;

	private:
		key_t _key;

		std::vector<rich_data_entry> _entries;
	};
}

#endif