#ifndef PE_LIBRARY_DOS_BUILDER_HPP
#define PE_LIBRARY_DOS_BUILDER_HPP

#include <pe_library/dos.hpp>
#include <pe_library/details/headers/image_dos_header.hpp>

namespace pe_library::details::builders
{
	class dos_builder
	{
	public:
		bytecode dos_to_bytecode(dos const& dos);

	private:
		dos const* _dos;

		bytecode _result;

		void write_header() noexcept;
		void write_stub() noexcept;
	};
}

#endif