#ifndef PE_LIBRARY_DOS_PARSER_HPP
#define PE_LIBRARY_DOS_PARSER_HPP

#include <fstream>

#include <pe_library/file.hpp>

namespace pe_library::details::parsers
{
	class dos_parser
	{
	public:
		void parse(std::ifstream* file_stream);
		dos const& get_parser_dos() const noexcept;

	private:
		std::ifstream* _file_stream;

		headers::image_dos_header _header;
		bytecode _stub;
		dos _dos;

	private:
		void read_header();
		void check_header_validation() const;
		void check_e_magic_signature() const;
		void check_e_lfanew_alignment() const;
		void read_stub();
		void make_dos();
	};
}

#endif