#ifndef PE_LIBRARY_IMAGE_LOAD_CONFIG_DIRECTORY32_HPP
#define PE_LIBRARY_IMAGE_LOAD_CONFIG_DIRECTORY32_HPP

#include <cstdint>

#include <pe_library/details/headers/image_load_config_code_integrity.hpp>

namespace pe_library::details::headers
{
	struct image_load_config_directory32
	{
        std::uint32_t size;
        std::uint32_t time_date_stamp;
        std::uint16_t major_version;
        std::uint16_t minor_version;
        std::uint32_t global_flags_clear;
        std::uint32_t global_flags_set;
        std::uint32_t critical_section_default_timeout;
        std::uint32_t decommit_free_block_threshold;
        std::uint32_t decommit_total_free_threshold;
        std::uint32_t lock_prefix_table;
        std::uint32_t maximum_allocation_size;
        std::uint32_t virtual_memory_threshold;
        std::uint32_t process_heap_flags;
        std::uint32_t process_affinity_mask;
        std::uint16_t csd_version;
        std::uint16_t dependent_load_flags;
        std::uint32_t edit_list;
        std::uint32_t security_cookie;
        std::uint32_t se_handler_table;
        std::uint32_t se_handler_count;
        std::uint32_t guard_cf_check_function_pointer;
        std::uint32_t guard_cf_dispatch_function_pointer;
        std::uint32_t guard_cf_function_table;
        std::uint32_t guard_cf_function_count;
        std::uint32_t guard_flags;
        image_load_config_code_integrity code_integrity;
        std::uint32_t guard_address_taken_iat_entry_table;
        std::uint32_t guard_address_taken_iat_entry_count;
        std::uint32_t guard_long_jump_target_table;
        std::uint32_t guard_long_jump_target_count;
        std::uint32_t dynamic_value_reloc_table;
        std::uint32_t chpe_metadata_pointer;
        std::uint32_t guard_rf_failure_routine;
        std::uint32_t guard_rf_failure_routine_function_pointer;
        std::uint32_t dynamic_value_reloc_table_offset;
        std::uint16_t dynamic_value_reloc_table_section;
        std::uint16_t reserved2;
        std::uint32_t guard_rf_verify_stack_pointer_function_pointer;
        std::uint32_t hot_patch_table_offset;
        std::uint32_t reserved3;
        std::uint32_t enclave_configuration_pointer;
        std::uint32_t volatile_metadata_pointer;
        std::uint32_t guard_eh_continuation_table;
        std::uint32_t guard_eh_continuation_count;
        std::uint32_t guard_xfg_check_function_pointer;
        std::uint32_t guard_xfg_dispatch_function_pointer;
        std::uint32_t guard_xfg_table_dispatch_function_pointer;
        std::uint32_t cast_guard_os_determined_failure_mode;
        std::uint32_t guard_memcpy_function_pointer;
	};
}

#endif