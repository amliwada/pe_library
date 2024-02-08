#ifndef PE_LIBRARY_BYTECODE_HELPER_HPP
#define PE_LIBRARY_BYTECODE_HELPER_HPP

#include <stdexcept>

#include <pe_library/bytecode.hpp>

namespace pe_library::details::helpers
{
	class bytecode_helper
	{
	public:
		template<class t>
		static inline t const* const read_value_from_position(bytecode const& bytecode, std::size_t position)
		{
			if ((position + sizeof(t)) > bytecode.size())
			{
				throw std::out_of_range{ "read out of range" };
			}

			return reinterpret_cast<t const* const>(bytecode.data() + position);
		}

		template<class t>
		static inline void write_value_to_position(bytecode* bytes, const t value, const std::uint64_t position)
		{
			*reinterpret_cast<t*>(bytes->data() + position) = value;
		}

		static void align(bytecode* bytes, std::uint64_t align);
	};
}

#endif