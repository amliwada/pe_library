#ifndef PE_LIBRARY_DOS_HPP
#define PE_LIBRARY_DOS_HPP

#include <array>

#include <pe_library/details/headers/image_dos_header.hpp>
#include <pe_library/bytecode.hpp>

namespace pe_library
{
	class dos
	{
	public:
		dos() noexcept;

		std::uint16_t get_e_magic() const noexcept;

		std::uint16_t get_e_cblp() const noexcept;
		void set_e_cblp(std::uint16_t value) noexcept;

		std::uint16_t get_e_cp() const noexcept;
		void set_e_cp(std::uint16_t value) noexcept;

		std::uint16_t get_e_crlc() const noexcept;
		void set_e_crlc(std::uint16_t value) noexcept;

		std::uint16_t get_e_cparhdr() const noexcept;
		void set_e_cparhdr(std::uint16_t value) noexcept;

		std::uint16_t get_e_minalloc() const noexcept;
		void set_e_minalloc(std::uint16_t value) noexcept;

		std::uint16_t get_e_maxalloc() const noexcept;
		void set_e_maxalloc(std::uint16_t value) noexcept;

		std::uint16_t get_e_ss() const noexcept;
		void set_e_ss(std::uint16_t value) noexcept;

		std::uint16_t get_e_sp() const noexcept;
		void set_e_sp(std::uint16_t value) noexcept;

		std::uint16_t get_e_csum() const noexcept;
		void set_e_csum(std::uint16_t value) noexcept;

		std::uint16_t get_e_ip() const noexcept;
		void set_e_ip(std::uint16_t value) noexcept;

		std::uint16_t get_e_cs() const noexcept;
		void set_e_cs(std::uint16_t value) noexcept;

		std::uint16_t get_e_lfarlc() const noexcept;
		void set_e_lfarlc(std::uint16_t value) noexcept;

		std::uint16_t get_e_ovno() const noexcept;
		void set_e_ovno(std::uint16_t value) noexcept;

		std::array<std::uint16_t, 4> const& get_e_res() noexcept;

		template<std::size_t size>
		constexpr void set_e_res(std::uint16_t(&value)[size]) noexcept
		{
			static_assert(size == details::headers::image_dos_header::e_res_size);

			std::memcpy(this->_header.e_res, value, details::headers::image_dos_header::e_res_size);
		}

		std::uint16_t get_e_oemid() const noexcept;
		void set_e_oemid(std::uint16_t value) noexcept;

		std::uint16_t get_e_oeminfo() const noexcept;
		void set_e_oeminfo(std::uint16_t value) noexcept;

		std::array<std::uint16_t, details::headers::image_dos_header::e_res2_size> const& get_e_res2() const noexcept;

		template<std::size_t size>
		constexpr void set_e_res2(std::uint16_t(&value)[size]) noexcept
		{
			static_assert(size == details::headers::image_dos_header::e_res2_size);

			std::memcpy(this->_header.e_res2, value, details::headers::image_dos_header::e_res2_size);
		}

		bytecode const& get_stub() const noexcept;
		void set_stub(bytecode&& stub) noexcept;

		std::size_t get_size() const noexcept;

		details::headers::image_dos_header get_header() const noexcept;

	private:
		details::headers::image_dos_header _header;

		bytecode _stub;
	};
}

#endif