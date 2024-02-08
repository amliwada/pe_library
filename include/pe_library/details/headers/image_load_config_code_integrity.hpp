#ifndef PE_LIBRARY_IMAGE_LOAD_CONFIG_CODE_INTEGRITY_HPP
#define PE_LIBRARY_IMAGE_LOAD_CONFIG_CODE_INTEGRITY_HPP

#include <cstdint>

namespace pe_library::details::headers
{
    struct image_load_config_code_integrity
    {
        std::uint16_t flags;
        std::uint16_t catalog;
        std::uint32_t catalog_offset;
        std::uint32_t reserved;
    };
}

#endif