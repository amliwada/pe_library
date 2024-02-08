#include <ciso646>

#include <pe_library/details/parsers/dos_parser.hpp>

void pe_library::details::parsers::dos_parser::parse(std::ifstream* file_stream)
{
	this->_file_stream = file_stream;

	this->read_header();
	this->check_header_validation();
	this->read_stub();
	this->make_dos();
}

void pe_library::details::parsers::dos_parser::read_header()
{
	this->_file_stream->read(reinterpret_cast<char*>(&this->_header), sizeof(this->_header));

	if (this->_file_stream->bad() or this->_file_stream->eof())
	{
		throw std::exception{ "no dos header" };
	}
}

void pe_library::details::parsers::dos_parser::check_header_validation() const
{
	this->check_e_magic_signature();
	this->check_e_lfanew_alignment();
}

void pe_library::details::parsers::dos_parser::check_e_magic_signature() const
{
	if (this->_header.e_magic not_eq headers::image_dos_header::signature)
	{
		throw std::exception{ "bad dos magic" };
	}
}

void pe_library::details::parsers::dos_parser::check_e_lfanew_alignment() const
{
	if ((this->_header.e_lfanew % sizeof(std::uint32_t)) not_eq 0)
	{
		throw std::exception{ "bad nt magic" };
	}
}

void pe_library::details::parsers::dos_parser::read_stub()
{
	auto size_of_dos_stub{ this->_header.e_lfanew - this->_file_stream->tellg() };
	this->_stub.resize(size_of_dos_stub);

	this->_file_stream->read(reinterpret_cast<char*>(this->_stub.data()), this->_stub.size());

	if (this->_file_stream->bad() or this->_file_stream->eof())
	{
		throw std::exception{ "bad dos stub" };
	}
}

void pe_library::details::parsers::dos_parser::make_dos()
{
	this->_dos.set_e_cblp(_header.e_cblp);
	this->_dos.set_e_cp(_header.e_cp);
	this->_dos.set_e_crlc(_header.e_crlc);
	this->_dos.set_e_cparhdr(_header.e_cparhdr);
	this->_dos.set_e_minalloc(_header.e_minalloc);
	this->_dos.set_e_maxalloc(_header.e_maxalloc);
	this->_dos.set_e_ss(_header.e_ss);
	this->_dos.set_e_sp(_header.e_sp);
	this->_dos.set_e_csum(_header.e_csum);
	this->_dos.set_e_ip(_header.e_ip);
	this->_dos.set_e_cs(_header.e_cs);
	this->_dos.set_e_lfarlc(_header.e_lfarlc);
	this->_dos.set_e_ovno(_header.e_ovno);
	this->_dos.set_e_res(_header.e_res);
	this->_dos.set_e_oemid(_header.e_oemid);
	this->_dos.set_e_oeminfo(_header.e_oeminfo);
	this->_dos.set_e_res2(_header.e_res2);
	this->_dos.set_stub(std::move(this->_stub));
}

pe_library::dos const& pe_library::details::parsers::dos_parser::get_parser_dos() const noexcept
{
	return this->_dos;
}