#include <thin/cvstrar.hpp>

extern "C" int puts(const char*) noexcept;

template<size_t COUNT>
constexpr size_t count(thin::strar<COUNT> strings)
{
	return strings.size();
}

int main()
{
	using namespace thin;

	// Compile-time checks
	constexpr strar zero_allowed;
	constexpr strar<1> unset;
	constexpr strar<5> one_to_five {"1", "2", "3", "4", "5"};
	constexpr strar hello_world {"Hello", "C++", "world!"};
	static_assert(zero_allowed.size() == 0);
	static_assert(count(strar {"A", "B", "C"}) == 3);
	static_assert(unset[0] == nullptr);
	static_assert(unset[0].length == 0);
	static_assert(one_to_five[0][0] == '1');
	static_assert((*hello_world.begin())[0] == 'H');
	static_assert(*(hello_world.end() - 1)[0] == 'w');
	static_assert(hello_world.size() == 3);
	static_assert(hello_world[0].length == 5);
	static_assert(hello_world.back().length == 6);

	puts("Success.");
	return 0;
}
