#ifndef PE_LIBRARY_DOS_HEADER_H
#define PE_LIBRARY_DOS_HEADER_H

#include <cstdint>

namespace pe_library::details::headers
{
    struct image_dos_header
    {
        static constexpr std::uint16_t signature{ 0x5a4d };

        static constexpr std::size_t e_res_size{ 4 };
        static constexpr std::size_t e_res2_size{ 10 };

        std::uint16_t e_magic;
        std::uint16_t e_cblp;
        std::uint16_t e_cp;
        std::uint16_t e_crlc;
        std::uint16_t e_cparhdr;
        std::uint16_t e_minalloc;
        std::uint16_t e_maxalloc;
        std::uint16_t e_ss;
        std::uint16_t e_sp;
        std::uint16_t e_csum;
        std::uint16_t e_ip;
        std::uint16_t e_cs;
        std::uint16_t e_lfarlc;
        std::uint16_t e_ovno;
        std::uint16_t e_res[e_res_size];
        std::uint16_t e_oemid;
        std::uint16_t e_oeminfo;
        std::uint16_t e_res2[e_res2_size];
        std::uint32_t e_lfanew;
    };
}

#endif