#pragma once
#include "cvstr.hpp"
#include "default_size_t.hpp"
#include "ra.hpp"

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<size_t N, class SIZE_T = DEFAULT_SIZE_T>
struct cvstrar
{
	ra<cvstr, N, SIZE_T> arr {};

	// Utilities
	ND CX SIZE_T size() CNX { return static_cast<SIZE_T>(N); }
	// Accessors
	ND CX const cvstr& back() CNX { return arr.back(); }
	ND CX const cvstr& operator[](size_t index) CNX { return arr[index]; }
	// Operators
	ND CX operator cvstr*() NX { return arr.begin(); }
	ND CX operator const cvstr*() CNX { return arr.begin(); }
	// Iterators
	ND CX cvstr* begin() NX { return arr.begin(); }
	ND CX cvstr* end() NX { return arr.end(); }
	ND CX const cvstr* begin() CNX { return arr.begin(); }
	ND CX const cvstr* end() CNX { return arr.end(); }
};
template<class... varargs>
cvstrar(varargs...) -> cvstrar<sizeof...(varargs)>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
