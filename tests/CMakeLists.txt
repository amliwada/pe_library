cmake_minimum_required(VERSION 3.12)

project(pe_library_tests VERSION 1.0 LANGUAGES CXX)

add_executable(${PROJECT_NAME}
	main.cpp

	file_parser_test/file_parser_test.cpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(googletest GIT_REPOSITORY https://github.com/google/googletest.git GIT_TAG release-1.11.0)
FetchContent_MakeAvailable(googletest)

target_link_libraries(${PROJECT_NAME} PRIVATE pe_library PRIVATE gtest_main)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/$<CONFIG>"
)

message(STATUS, ${CMAKE_CURRENT_BINARY_DIR})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/files DESTINATION ${CMAKE_CURRENT_BINARY_DIR})