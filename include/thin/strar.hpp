#pragma once
#include "default_size_t.hpp"
#include "ra.hpp"

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<size_t N = 0, class SIZE_T = DEFAULT_SIZE_T>
struct strar
{
	ra<const char*, N, SIZE_T> arr {};

	// Utilities
	ND CX SIZE_T size() CNX { return static_cast<SIZE_T>(N); }
	// Accessors
	ND CX const char*& back() NX { return arr.back(); }
	ND CX const char*& operator[](size_t index) NX { return arr[index]; }
	ND CX const char* const& back() CNX { return arr.back(); }
	ND CX const char* const& operator[](size_t index) CNX { return arr[index]; }
	// Operators
	ND CX operator const char**() NX { return arr.begin(); }
	ND CX operator const char* const *() CNX { return arr.begin(); }
	// Iterators
	ND CX const char** begin() NX { return arr.begin(); }
	ND CX const char** end() NX { return arr.end(); }
	ND CX const char* const* begin() CNX { return arr.begin(); }
	ND CX const char* const* end() CNX { return arr.end(); }
};
template<class... varargs>
strar(varargs...) -> strar<sizeof...(varargs)>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
