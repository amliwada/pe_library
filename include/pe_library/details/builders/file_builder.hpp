#ifndef PE_LIBRARY_FILE_BUILDER_HPP
#define PE_LIBRARY_FILE_BUILDER_HPP

#include <fstream>

#include <pe_library/file.hpp>
#include <pe_library/details/builders/rich_data_builder.hpp>
#include <pe_library/details/builders/dos_builder.hpp>
#include <pe_library/details/builders/nt_builder.hpp>
#include <pe_library/details/builders/sections_builder.hpp>

namespace pe_library::details::builders
{
	class file_builder
	{
	public:
		void build(file const& target_file, std::filesystem::path const& target_path);

	private:
		file const* _target_file;
		std::ofstream _file_stream;;
		rich_data_builder _rich_data_builder;
		dos_builder _dos_builder;
		sections_builder _sections_builder;
		nt_builder _nt_builder;
		bytecode _headers_bytecode;

	private:
		void create_file(std::filesystem::path const& target_path);
		void build_rich_data();
		void build_dos();
		void reserve_headers_bytecode();
		void build_sections();
		void build_nt();
		void write_builded_data_to_file();
		void insert_headers_to_file();
		void insert_sections_container_to_file();
		void insert_section_to_file(sections_container::const_iterator section_iterator);
	};
}

#endif