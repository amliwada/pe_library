#ifndef PE_LIBRARY_FILE_PARSER_HPP
#define PE_LIBRARY_FILE_PARSER_HPP

#include <fstream>

#include <pe_library/file.hpp>
#include <pe_library/details/parsers/dos_parser.hpp>
#include <pe_library/details/parsers/rich_data_parser.hpp>
#include <pe_library/details/parsers/nt_headers_parser.hpp>
#include <pe_library/details/parsers/sections_parser.hpp>
#include <pe_library/pe_version.hpp>

namespace pe_library::details::parsers
{
	class file_parser
	{
	public:
		file&& parse_file(std::filesystem::path const& path_to_file);

	private:
		std::ifstream _file_stream;

		file _parsed_file;

		dos_parser _dos_parser;
		rich_data_parser _rich_data_parser;

		nt_headers_parser _nt_headers_parser;

		sections_parser _section_parser;

		addresses_provider _addresses_provider;

		pe_version _version;

	private:
		void open_file(std::filesystem::path const& path_to_file);
		void parse_dos();
		void parse_rich_data();
		void remove_rich_data_from_dos_stub();
		void parse_nt_headers();
		void parse_sections();
		void make_addresses_provider();
		void set_nt_in_parsed_file();
		void set_version();
		void make_file();
	};
}

#endif