#ifndef PE_LIBRARY_ADDRESSES_PROVIDER_HPP
#define PE_LIBRARY_ADDRESSES_PROVIDER_HPP

#include <optional>

#include <pe_library/details/parsers/sections_parser.hpp>
#include <pe_library/data_address.hpp>

namespace pe_library::details
{
	class addresses_provider
	{
	public:
		addresses_provider() = default;
		addresses_provider(std::uint64_t image_base, parsers::sections_parser* sections_parser);

		std::optional<data_address> imm_to_data_address(std::uint64_t imm) const noexcept;

	private:
		std::uint64_t _image_base;

		parsers::sections_parser* _sections_parser;
	};
}

#endif