#ifndef PE_LIBRARY_SECTIONS_PARSER_HPP
#define PE_LIBRARY_SECTIONS_PARSER_HPP

#include <fstream>
#include <utility>
#include <optional>

#include <pe_library/details/headers/image_section_header.hpp>
#include <pe_library/details/containers/sections_container.hpp>
#include <pe_library/data_address.hpp>

namespace pe_library::details::parsers
{
	class sections_parser
	{
	public:
		void parse_sections(std::ifstream* file_stream);

		sections_container&& get_parsed_sections() noexcept;

		std::optional<data_address> rva_to_data_address(std::uint64_t rva) const noexcept;

	private:
		std::ifstream* _file_stream;

		std::list<std::pair<headers::image_section_header, sections_container::iterator>> _headers;
		sections_container _parsed_sections;

		headers::image_section_header _parsed_section_header;

	private:
		void read_section_header();
		bool is_valid_section_header();
		void add_section();
		bytecode read_section_bytecode();
		bool is_address_in_section(std::uint64_t address, headers::image_section_header section_header) const noexcept;
	};
}

#endif