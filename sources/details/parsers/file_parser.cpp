#include <pe_library/details/parsers/file_parser.hpp>

pe_library::file&& pe_library::details::parsers::file_parser::parse_file(std::filesystem::path const& path_to_file)
{
	this->open_file(path_to_file);
	this->parse_dos();
	this->parse_rich_data();

	if (this->_parsed_file.has_rich_data())
	{
		this->remove_rich_data_from_dos_stub();
	}

	this->parse_nt_headers();
	this->parse_sections();

	this->make_addresses_provider();

	this->set_nt_in_parsed_file();

	this->set_version();

	this->make_file();

	return std::move(this->_parsed_file);
}

void pe_library::details::parsers::file_parser::open_file(std::filesystem::path const& path_to_file)
{
	this->_file_stream.open(path_to_file, std::ios::binary);
}

void pe_library::details::parsers::file_parser::parse_dos()
{
	this->_dos_parser.parse(&this->_file_stream);
	auto parsed_dos{ this->_dos_parser.get_parser_dos() };
	this->_parsed_file.set_dos(std::move(parsed_dos));
}

void pe_library::details::parsers::file_parser::parse_rich_data()
{
	this->_rich_data_parser.parse_rich_data_in_dos(_parsed_file.get_dos());
	auto parsed_rich_data{ this->_rich_data_parser.get_parsed_rich_data() };
	
	if (parsed_rich_data.has_value())
	{
		this->_parsed_file.set_rich_data(std::move(*parsed_rich_data));
	}
}

void pe_library::details::parsers::file_parser::remove_rich_data_from_dos_stub()
{
	auto new_dos{ this->_parsed_file.get_dos() };
	auto new_dos_stub{ new_dos.get_stub() };
	new_dos_stub.resize(this->_rich_data_parser.get_rich_data_position());
	new_dos.set_stub(std::move(new_dos_stub));
	this->_parsed_file.set_dos(std::move(new_dos));
}

void pe_library::details::parsers::file_parser::parse_nt_headers()
{
	this->_nt_headers_parser.parse_headers(&this->_file_stream);
}

void pe_library::details::parsers::file_parser::parse_sections()
{
	this->_section_parser.parse_sections(&this->_file_stream);
}

void pe_library::details::parsers::file_parser::make_addresses_provider()
{
	_addresses_provider = addresses_provider(this->_nt_headers_parser.get_image_base(), &this->_section_parser);
}

void pe_library::details::parsers::file_parser::set_nt_in_parsed_file()
{
	auto parsed_nt{ this->_nt_headers_parser.make_nt(&this->_addresses_provider) };
	this->_parsed_file.set_nt(std::move(parsed_nt));
}

void pe_library::details::parsers::file_parser::set_version()
{
	if (this->_nt_headers_parser.get_magic() == headers::constants::nt_headers::optional_header_magic_32)
	{
		this->_version = pe_version::pe;
	}
	else if (this->_nt_headers_parser.get_magic() == headers::constants::nt_headers::optional_header_magic_64)
	{
		this->_version = pe_version::pe_plus;
	}
	else
	{
		throw std::exception{ "bad version" };
	}

	this->_parsed_file.set_version(this->_version);
}

void pe_library::details::parsers::file_parser::make_file()
{
	this->_parsed_file.set_sections(this->_section_parser.get_parsed_sections());
}