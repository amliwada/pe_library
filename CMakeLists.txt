cmake_minimum_required(VERSION 3.12)

project(pe_library VERSION 1.0 LANGUAGES CXX)

add_library(${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

target_sources(${PROJECT_NAME}
	PRIVATE
		sources/dos.cpp
		sources/rich_data.cpp
		sources/section.cpp
		sources/nt.cpp
		sources/file.cpp
		sources/rich_data_entry.cpp

		sources/data_address.cpp
		sources/data_reference.cpp
		sources/interval.cpp

		sources/details/parsers/file_parser.cpp
		sources/details/parsers/dos_parser.cpp
		sources/details/parsers/rich_data_parser.cpp
		sources/details/parsers/nt_headers_parser.cpp
		sources/details/parsers/sections_parser.cpp

		sources/details/helpers/bytes_helper.cpp
		sources/details/helpers/intervals_helper.cpp
		sources/details/helpers/bytecode_helper.cpp

		sources/details/containers/sections_container.cpp
		sources/details/containers/data_intervals_container.cpp

		sources/details/providers/addresses_provider.cpp

		sources/details/builders/file_builder.cpp
		sources/details/builders/rich_data_builder.cpp
		sources/details/builders/dos_builder.cpp
		sources/details/builders/sections_builder.cpp
		sources/details/builders/nt_builder.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/sources
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

set(public_headers
	include/pe_library/dos.hpp
	include/pe_library/rich.hpp
	include/pe_library/section.hpp
	include/pe_library/nt.hpp
	include/pe_library/file.hpp

	include/pe_library/bytecode.hpp

	include/pe_library/data_address.hpp
	include/pe_library/reference_type.hpp
	include/pe_library/data_reference.hpp
	include/pe_library/bytecode_helper.hpp

	include/pe_library/interval.hpp

	include/pe_library/pe_version.hpp

	include/pe_library/details/helpers/enum_helper.hpp
	include/pe_library/details/helpers/bytes_helper.hpp
	include/pe_library/details/helpers/intervals_helper.hpp

	include/pe_library/details/parsers/file_parser.hpp
	include/pe_library/details/parsers/rich_data_parser.hpp
	include/pe_library/details/parsers/dos_parser.hpp
	include/pe_library/details/parsers/sections_parser.hpp

	include/pe_library/details/headers/image_dos_header.hpp
	include/pe_library/details/headers/image_file_header.hpp
	include/pe_library/details/headers/image_nt_headers32.hpp
	include/pe_library/details/headers/image_nt_headers64.hpp
	include/pe_library/details/headers/image_optional_header32.hpp
	include/pe_library/details/headers/image_optional_header64.hpp
	include/pe_library/details/headers/image_section_header.hpp
	include/pe_library/details/headers/nt_headers_parser.hpp
	include/pe_library/details/headers/image_data_directory.hpp
	include/pe_library/details/headers/image_import_descriptor.hpp
	include/pe_library/details/headers/image_load_config_directory32.hpp
	include/pe_library/details/headers/image_load_config_directory64.hpp
	include/pe_library/details/headers/image_load_config_code_integrity.hpp

	include/pe_library/details/constants/nt_constants.hpp

	include/pe_library/details/containers/sections_container.hpp
	include/pe_library/details/containers/data_intervals_container.hpp

	include/pe_library/details/providers/addresses_provider.hpp

	include/pe_library/details/builders/file_builder.hpp
	include/pe_library/details/builders/rich_data_builder.hpp
	include/pe_library/details/builders/dos_builder.hpp
	include/pe_library/details/builders/sections_builder.hpp
	include/pe_library/details/builders/nt_builder.hpp
)

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${public_headers}")

include(GNUInstallDirs)

install(TARGETS ${PROJECT_NAME}
    EXPORT "${PROJECT_NAME}_targets"
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}
    INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)

install(EXPORT "${PROJECT_NAME}_targets"
    FILE "${PROJECT_NAME}_targets.cmake"
    NAMESPACE ${namespace}::
    DESTINATION cmake
)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_config_version.cmake"
    VERSION "${version}"
    COMPATIBILITY AnyNewerVersion
)

configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/cmake/${PROJECT_NAME}_config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_config.cmake"
    INSTALL_DESTINATION cmake
)

install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}_config_version.cmake"
    DESTINATION cmake
)

export(EXPORT "${PROJECT_NAME}_targets"
    FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${PROJECT_NAME}_targets.cmake"
    NAMESPACE ${namespace}::
)