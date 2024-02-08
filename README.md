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