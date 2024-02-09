#include "file_parser_test.hpp"

void file_parser_test::SetUp()
{
	this->_target_file = pe_library::file::parse("files\\main64.exe");
}

TEST_F(file_parser_test, dos_parser)
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