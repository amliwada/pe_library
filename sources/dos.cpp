#include <exception>

#include <pe_library/dos.hpp>
#include <pe_library/details/helpers/bytes_helper.hpp>
#include <pe_library/details/helpers/bytecode_helper.hpp>

pe_library::dos::dos() noexcept
	: _header{ 0 }
{
	this->_header.e_magic = details::headers::image_dos_header::signature;
}

std::uint16_t pe_library::dos::get_e_magic() const noexcept
{
	return this->_header.e_magic;
}

std::uint16_t pe_library::dos::get_e_cblp() const noexcept
{
	return this->_header.e_cblp;
}

void pe_library::dos::set_e_cblp(std::uint16_t value) noexcept
{
	this->_header.e_cblp = value;
}

std::uint16_t pe_library::dos::get_e_cp() const noexcept
{
	return this->_header.e_cp;
}

void pe_library::dos::set_e_cp(std::uint16_t value) noexcept
{
	this->_header.e_cp = value;
}

std::uint16_t pe_library::dos::get_e_crlc() const noexcept
{
	return this->_header.e_crlc;
}

void pe_library::dos::set_e_crlc(std::uint16_t value) noexcept
{
	this->_header.e_crlc = value;
}

std::uint16_t pe_library::dos::get_e_cparhdr() const noexcept
{
	return this->_header.e_cparhdr;
}

void pe_library::dos::set_e_cparhdr(std::uint16_t value) noexcept
{
	this->_header.e_cparhdr = value;
}

std::uint16_t pe_library::dos::get_e_minalloc() const noexcept
{
	return this->_header.e_minalloc;
}

void pe_library::dos::set_e_minalloc(std::uint16_t value) noexcept
{
	this->_header.e_minalloc = value;
}

std::uint16_t pe_library::dos::get_e_maxalloc() const noexcept
{
	return this->_header.e_maxalloc;
}

void pe_library::dos::set_e_maxalloc(std::uint16_t value) noexcept
{
	this->_header.e_maxalloc = value;
}

std::uint16_t pe_library::dos::get_e_ss() const noexcept
{
	return this->_header.e_ss;
}

void pe_library::dos::set_e_ss(std::uint16_t value) noexcept
{
	this->_header.e_ss = value;
}

std::uint16_t pe_library::dos::get_e_sp() const noexcept
{
	return this->_header.e_sp;
}

void pe_library::dos::set_e_sp(std::uint16_t value) noexcept
{
	this->_header.e_sp = value;
}

std::uint16_t pe_library::dos::get_e_csum() const noexcept
{
	return this->_header.e_csum;
}

void pe_library::dos::set_e_csum(std::uint16_t value) noexcept
{
	this->_header.e_csum = value;
}

std::uint16_t pe_library::dos::get_e_ip() const noexcept
{
	return this->_header.e_ip;
}

void pe_library::dos::set_e_ip(std::uint16_t value) noexcept
{
	this->_header.e_ip = value;
}

std::uint16_t pe_library::dos::get_e_cs() const noexcept
{
	return this->_header.e_cs;
}

void pe_library::dos::set_e_cs(std::uint16_t value) noexcept
{
	this->_header.e_cs = value;
}

std::uint16_t pe_library::dos::get_e_lfarlc() const noexcept
{
	return this->_header.e_lfarlc;
}

void pe_library::dos::set_e_lfarlc(std::uint16_t value) noexcept
{
	this->_header.e_lfarlc = value;
}

std::uint16_t pe_library::dos::get_e_ovno() const noexcept
{
	return this->_header.e_ovno;
}

void pe_library::dos::set_e_ovno(std::uint16_t value) noexcept
{
	this->_header.e_ovno = value;
}

std::array<std::uint16_t, pe_library::details::headers::image_dos_header::e_res_size> const& pe_library::dos::get_e_res() noexcept
{
	return reinterpret_cast<std::array<std::uint16_t, pe_library::details::headers::image_dos_header::e_res_size> const&>(this->_header.e_res);
}

std::uint16_t pe_library::dos::get_e_oemid() const noexcept
{
	return this->_header.e_oemid;
}

void pe_library::dos::set_e_oemid(std::uint16_t value) noexcept
{
	this->_header.e_oemid = value;
}

std::uint16_t pe_library::dos::get_e_oeminfo() const noexcept
{
	return this->_header.e_oeminfo;
}

void pe_library::dos::set_e_oeminfo(std::uint16_t value) noexcept
{
	this->_header.e_oeminfo = value;
}

std::array<std::uint16_t, pe_library::details::headers::image_dos_header::e_res2_size> const& pe_library::dos::get_e_res2() const noexcept
{
	return reinterpret_cast<std::array<std::uint16_t, pe_library::details::headers::image_dos_header::e_res2_size> const&>(this->_header.e_res2);
}

pe_library::bytecode const& pe_library::dos::get_stub() const noexcept
{
	return this->_stub;
}

std::size_t pe_library::dos::get_size() const noexcept
{
	return sizeof(this->_header) + this->_stub.size() + 0x10;
}

pe_library::details::headers::image_dos_header pe_library::dos::get_header() const noexcept
{
	auto header{ this->_header };
	header.e_lfanew = static_cast<std::uint32_t>(this->get_size());
	return header;
}

void pe_library::dos::set_stub(bytecode&& stub) noexcept
{
	this->_stub = std::move(stub);
}