#ifndef __DEF_EXPRESSION__
#define __DEF_EXPRESSION__

#include <cstddef>

template<typename V, typename T, size_t N>
struct Expression {
public:

	template<size_t i>
	T get() const {
		static_assert(i >= 0 && i < N, "out of bounds");
		return static_cast<const V&>(*this).template _get<i>();
	}
};

#endif