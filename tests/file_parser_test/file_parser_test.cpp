#include "file_parser_test.hpp"

void file_parser_test::SetUp()
{
	this->_target_file = pe_library::file::parse("files\\main64.exe");
}

TEST_F(file_parser_test, dos_parser_test)
{
	decltype(auto) dos{ this->_target_file.get_dos() };

	ASSERT_EQ(dos.get_e_magic(), 0x5a4d);
	ASSERT_EQ(dos.get_e_cblp(), 0x90);
	ASSERT_EQ(dos.get_e_cp(), 0x3);
	ASSERT_EQ(dos.get_e_crlc(), 0x0);
	ASSERT_EQ(dos.get_e_cparhdr(), 0x4);
	ASSERT_EQ(dos.get_e_minalloc(), 0x0);
	ASSERT_EQ(dos.get_e_maxalloc(), 0xffff);
	ASSERT_EQ(dos.get_e_ss(), 0x0);
	ASSERT_EQ(dos.get_e_sp(), 0xb8);
	ASSERT_EQ(dos.get_e_csum(), 0x0);
	ASSERT_EQ(dos.get_e_ip(), 0x0);
	ASSERT_EQ(dos.get_e_cs(), 0x0);
	ASSERT_EQ(dos.get_e_lfarlc(), 0x40);
	ASSERT_EQ(dos.get_e_ovno(), 0x0);
	ASSERT_EQ(dos.get_e_oemid(), 0x0);
	ASSERT_EQ(dos.get_e_oeminfo(), 0x0);
}

TEST_F(file_parser_test, rich_data_parser_test)
{
	decltype(auto) rich_data{ this->_target_file.get_rich_data() };
	decltype(auto) entries{ rich_data->get_entries() };

	ASSERT_EQ(entries.size(), 0xa);

	decltype(auto) first_entry{ entries.front() };

	ASSERT_EQ(first_entry.get_product_id(), 0x93);
	ASSERT_EQ(first_entry.get_build_id(), 0x7809);
	ASSERT_EQ(first_entry.get_count(), 0xa);

	decltype(auto) last_entry{ entries.back() };

	ASSERT_EQ(last_entry.get_product_id(), 0x102);
	ASSERT_EQ(last_entry.get_build_id(), 0x816e);
	ASSERT_EQ(last_entry.get_count(), 0x1);
}

TEST_F(file_parser_test, nt_headers_parser_test)
{
	decltype(auto) nt{ this->_target_file.get_nt() };

	ASSERT_EQ(nt.get_machine(), 0x8664);
	ASSERT_EQ(nt.get_time_date_stamp(), 0x65c01611);
	ASSERT_EQ(nt.get_characteristics(), 0x0022);
	ASSERT_EQ(nt.get_magic(), 0x20b);
	ASSERT_EQ(nt.get_major_linker_version(), 0xe);
	ASSERT_EQ(nt.get_minor_linker_version(), 0x26);
	ASSERT_EQ(nt.get_image_base(), 0x140000000);
	ASSERT_EQ(nt.get_section_alignment(), 0x1000);
	ASSERT_EQ(nt.get_file_alignment(), 0x200);
	ASSERT_EQ(nt.get_major_operating_system_version(), 0x6);
	ASSERT_EQ(nt.get_minor_operating_system_version(), 0x0);
	ASSERT_EQ(nt.get_major_image_version(), 0x0);
	ASSERT_EQ(nt.get_minor_image_version(), 0x0);
	ASSERT_EQ(nt.get_major_subsystem_version(), 0x6);
	ASSERT_EQ(nt.get_minor_subsystem_version(), 0x0);
	ASSERT_EQ(nt.get_win32_version_value(), 0x0);
	ASSERT_EQ(nt.get_checksum(), 0x0);
	ASSERT_EQ(nt.get_subsystem(), 0x3);
	ASSERT_EQ(nt.get_dll_characteristics(), 0x8160);
	ASSERT_EQ(nt.get_size_of_stack_reserve(), 0x100000);
	ASSERT_EQ(nt.get_size_of_stack_commit(), 0x1000);
	ASSERT_EQ(nt.get_size_of_heap_reserve(), 0x100000);
	ASSERT_EQ(nt.get_size_of_heap_commit(), 0x1000);
	ASSERT_EQ(nt.get_loader_flags(), 0x0);
}

TEST_F(file_parser_test, sections_parser_test)
{
	decltype(auto) sections{ this->_target_file.get_sections() };

	ASSERT_EQ(sections.size(), 0x7);

	decltype(auto) first_section{ sections.front() };

	ASSERT_EQ(first_section.get_name(), ".text");
	ASSERT_EQ(first_section.get_characteristics(), 0x60000020);
	ASSERT_EQ(first_section.get_virtual_size(), 0xf99);
}