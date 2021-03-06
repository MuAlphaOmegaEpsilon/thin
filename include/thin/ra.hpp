#pragma once
#include "default_size_t.hpp"
#include <assert.h>
#include <stddef.h>

#define NX noexcept
#define CNX const noexcept
#define CX constexpr
#define ND [[nodiscard]]

namespace thin
{
template<class T, size_t N = 0, class SIZE_T = DEFAULT_SIZE_T>
struct ra
{
	T data[N ? N : 1];

	// Utilities
	ND CX SIZE_T size() CNX { return static_cast<SIZE_T>(N); }
	// Accessors
	ND CX T& operator[](size_t index) NX
	{
		static_assert(N);
		assert(index < N);
		return data[index];
	}
	ND CX const T& operator[](size_t index) CNX
	{
		static_assert(N);
		assert(index < N);
		return data[index];
	}
	ND CX T& back() NX
	{
		static_assert(N);
		assert(N - 1 < N);
		return data[N - 1];
	}
	ND CX const T& back() CNX
	{
		static_assert(N);
		assert(N - 1 < N);
		return data[N - 1];
	}
	// Operators
	ND CX operator T*() NX
	{
		if constexpr(!N) return nullptr;
		return data;
	}
	ND CX operator const T*() CNX
	{
		if constexpr(!N) return nullptr;
		return data;
	}
	// Iterators
	ND CX T* begin() NX
	{
		if constexpr(!N) return nullptr;
		return operator T*();
	}
	ND CX T* end() NX
	{
		if constexpr(!N) return nullptr;
		return operator T*() + N;
	}
	ND CX const T* begin() CNX
	{
		if constexpr(!N) return nullptr;
		return operator const T*();
	}
	ND CX const T* end() CNX
	{
		if constexpr(!N) return nullptr;
		return operator const T*() + N;
	}
};
template<class T, class... varargs>
ra(T first, varargs... list) -> ra<T, 1 + sizeof...(varargs)>;
} // namespace thin

#undef NX
#undef CNX
#undef CX
#undef ND
