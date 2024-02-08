#include <ciso646>

#include <pe_library/details/builders/file_builder.hpp>
#include <pe_library/details/helpers/bytes_helper.hpp>
#include <pe_library/details/helpers/bytecode_helper.hpp>

void pe_library::details::builders::file_builder::build(file const& target_file, std::filesystem::path const& target_path)
{
	this->_target_file = &target_file;
	
	this->create_file(target_path);
	this->build_rich_data();
	this->build_dos();
	this->reserve_headers_bytecode();
	this->build_sections();
	this->build_nt();
	this->write_builded_data_to_file();
}

void pe_library::details::builders::file_builder::create_file(std::filesystem::path const& target_path)
{
	this->_file_stream.open(target_path, std::ios::binary);
}

void pe_library::details::builders::file_builder::build_rich_data()
{
	decltype(auto) rich_data{ this->_target_file->get_rich_data() };
	auto dos{ this->_target_file->get_dos() };

	if (rich_data.has_value())
	{
		this->_rich_data_builder.build(rich_data.value(), dos);
	}
}

void pe_library::details::builders::file_builder::build_dos()
{
	decltype(auto) dos_with_rich_data{ this->_rich_data_builder.get_dos_with_rich_data() };
	decltype(auto) dos_bytecode{ this->_dos_builder.dos_to_bytecode(dos_with_rich_data) };
	std::copy(dos_bytecode.begin(), dos_bytecode.end(), std::back_inserter(this->_headers_bytecode));
}

void pe_library::details::builders::file_builder::reserve_headers_bytecode()
{
	std::size_t size_of_headers
	{
		this->_target_file->get_dos().get_size() +
		this->_nt_builder.get_size_of_nt_headers(*this->_target_file) +
		this->_sections_builder.get_headers_size(*this->_target_file)
	};

	size_of_headers = details::helpers::bytes_helper::align_up(size_of_headers, this->_target_file->get_nt().get_file_alignment());

	this->_headers_bytecode.reserve(size_of_headers);
}

void pe_library::details::builders::file_builder::build_sections()
{
	this->_sections_builder.make_headers_bytecode(*this->_target_file, this->_headers_bytecode.capacity());
}

void pe_library::details::builders::file_builder::build_nt()
{
	auto nt_bytecode
	{
		this->_nt_builder.get_headers_bytecode(*this->_target_file, this->_sections_builder, this->_headers_bytecode.capacity())
	};

	std::copy(nt_bytecode.begin(), nt_bytecode.end(), std::back_inserter(this->_headers_bytecode));
}

void pe_library::details::builders::file_builder::write_builded_data_to_file()
{
	this->insert_headers_to_file();
	this->insert_sections_container_to_file();
}

void pe_library::details::builders::file_builder::insert_headers_to_file()
{
	auto sections_bytecode
	{
		this->_sections_builder.get_headers_bytecode()
	};
	
	std::copy(sections_bytecode.begin(), sections_bytecode.end(), std::back_inserter(this->_headers_bytecode));

	this->_headers_bytecode.resize(this->_headers_bytecode.capacity());

	this->_file_stream.write(reinterpret_cast<char const* const>(this->_headers_bytecode.data()), this->_headers_bytecode.size());
}

void pe_library::details::builders::file_builder::insert_sections_container_to_file()
{
	decltype(auto) sections{ this->_target_file->get_sections() };

	for (auto section_iterator{ sections .cbegin() }; section_iterator not_eq sections.cend(); ++section_iterator)
	{
		this->insert_section_to_file(section_iterator);
	}
}

void pe_library::details::builders::file_builder::insert_section_to_file(sections_container::const_iterator section_iterator)
{
	auto section_bytecode{ section_iterator->get_bytecode() };

	if (section_bytecode.size() > 0)
	{
		helpers::bytecode_helper::align(&section_bytecode, this->_target_file->get_nt().get_file_alignment());
		this->_file_stream.write(reinterpret_cast<char const* const>(section_bytecode.data()), section_bytecode.size());
	}
}