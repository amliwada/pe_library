#ifndef PE_LIBRARY_SECTIONS_BUILDER_HPP
#define PE_LIBRARY_SECTIONS_BUILDER_HPP

#include <map>

#include <pe_library/file.hpp>
#include <pe_library/details/headers/image_section_header.hpp>

namespace pe_library::details::builders
{
	class sections_builder
	{
	public:
		std::size_t get_headers_size(file const& target_file) const noexcept;

		void make_headers_bytecode(file const& target_file, std::uint64_t address_of_first_section);

		std::size_t get_size_of_image() const noexcept;

		std::uint64_t data_address_to_imm(data_address const& address, reference_type type) const;

		std::uint64_t get_size_of_code() const noexcept;
		std::uint64_t get_size_of_initialized_data() const noexcept;
		std::uint64_t get_size_of_uninitialized_data() const noexcept;

		std::uint64_t get_section_virtual_address(sections_container::iterator section_iterator) const;

		bytecode const& get_headers_bytecode() const noexcept;

	private:
		bytecode _headers_bytecode;

		std::uint64_t _size_of_code;
		std::uint64_t _size_of_initialized_data;
		std::uint64_t _size_of_uninitialized_data;

		std::uint64_t _raw_address;
		std::uint64_t _virtual_address;

		nt const* _nt;

		std::vector<std::pair<sections_container::const_iterator, headers::image_section_header>> _headers;

	private:
		headers::image_section_header make_section_header(section const& sec) const noexcept;
	};
}

#endif