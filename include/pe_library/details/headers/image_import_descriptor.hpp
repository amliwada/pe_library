#ifndef PE_LIBRARY_IMAGE_IMPORT_DESCRIPTOR_H
#define PE_LIBRARY_IMAGE_IMPORT_DESCRIPTOR_H

#include <cstdint>

namespace pe_library::details::headers
{
    struct image_import_descriptor
    {
        static constexpr std::size_t offset_of_original_first_thunk{ 0 };
        static constexpr std::size_t offset_of_first_thunk{ 16 };
        static constexpr std::size_t offset_of_name{ 12 };

        union {
            std::uint32_t characteristics;
            std::uint32_t original_first_thunk;
        };

        std::uint32_t time_date_stamp;

        std::uint32_t forwarder_chain;
        std::uint32_t name;
        std::uint32_t first_thunk;
    };
}

#endif