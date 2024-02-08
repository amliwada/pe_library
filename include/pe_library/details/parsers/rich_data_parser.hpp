#ifndef PE_LIBRARY_RICH_DATA_PARSER_H
#define PE_LIBRARY_RICH_DATA_PARSER_H

#include <optional>

#include <pe_library/rich_data.hpp>
#include <pe_library/dos.hpp>

namespace pe_library::details::parsers
{
	class rich_data_parser
	{
	public:
		void parse_rich_data_in_dos(dos const& target_dos);

		std::optional<rich_data> const& get_parsed_rich_data() const noexcept;

		std::size_t get_rich_data_position() const noexcept;

	private:
		std::optional<rich_data> _rich_data;

		std::size_t _rich_data_position;
	};
}

#endif