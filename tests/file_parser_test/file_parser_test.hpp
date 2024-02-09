#ifndef PE_LIBRARY_TESTING_FILE_PARSER_TEST_HPP
#define PE_LIBRARY_TESTING_FILE_PARSER_TEST_HPP

#include <gtest/gtest.h>

#include <pe_library/file.hpp>

struct file_parser_test
	: public testing::Test
{
	void SetUp();

	pe_library::file _target_file;
};

#endif