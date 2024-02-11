# pe_library
PE/PE+ editing library based on C++17

## Features

- Support for both 32 and 64-bits PE formats
- Doesn't use WinAPI
- Doesn't execute PE files
- No dependencies

## Example

#### main.cpp

```C++
#include <pe_library/file.hpp>

int main()
{
	auto file{ pe_library::file::parse("test_x64_file.exe") };

	pe_library::bytecode section_bytecode(0x999);
	auto new_section{ file.add_section(".nwsc", std::move(section_bytecode)) };

	file.write_bytecode_to_address({ 0xe9, 0x12, 0x01, 0x00, 0x00 }, file.get_entry_point_address());

	file.build("new_test_x64_file.exe");

	return 0;
}
```

### CMakeLists.txt

```CMake
add_executable(pe_library_example main.cpp)
set_target_properties(pe_library_example PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(pe_library GIT_REPOSITORY https://github.com/amliwada/pe_library.git GIT_TAG v1.0.0)
FetchContent_MakeAvailable(pe_library)

target_link_libraries(pe_library_example pe_library)
```

### More Examples

More examples can be found in the [tests](./tests/) directory.