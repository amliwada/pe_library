#include <pe_library/details/helpers/bytecode_helper.hpp>
#include <pe_library/details/helpers/bytes_helper.hpp>

void pe_library::details::helpers::bytecode_helper::align(bytecode* bytes, std::uint64_t align)
{
	bytes->resize(bytes_helper::align_up(bytes->size(), align));
}