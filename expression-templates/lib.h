#ifndef __DEF_LIB__
#define __DEF_LIB__

#include <cstddef>
#include <initializer_list>

#include "Expression.h"
#include "Vector.h"
#include "AddExpression.h"
#include "MinExpression.h"
#include "ScalarExpression.h"
#include "MulExpression.h"
#include "DivExpression.h"
#include "FuncExpression.h"

template <typename E1, typename E2, typename T, size_t N>
AddExpression<E1, E2, T, N>
operator+(Expression<E1, T, N> const& u, Expression<E2, T, N> const& v) {
	return AddExpression<E1, E2, T, N>(*static_cast<const E1*>(&u), *static_cast<const E2*>(&v));
}

template <typename E1, typename T, size_t N>
AddExpression<E1, ScalarExpression<T, N>, T, N>
operator+(Expression<E1, T, N> const& u, const T& v) {
	return AddExpression<E1, ScalarExpression<T, N>, T, N>(*static_cast<const E1*>(&u), *new ScalarExpression<T, N>(v));
}

template <typename E1, typename T, size_t N>
AddExpression<ScalarExpression<T, N>, E1, T, N>
operator+(const T& u, Expression<E1, T, N> const& v) {
	return AddExpression<ScalarExpression<T, N>, E1, T, N>(*new ScalarExpression<T, N>(u), *static_cast<const E1*>(&v));
}

template <typename E1, typename E2, typename T, size_t N>
MinExpression<E1, E2, T, N>
operator-(Expression<E1, T, N> const& u, Expression<E2, T, N> const& v) {
	return MinExpression<E1, E2, T, N>(*static_cast<const E1*>(&u), *static_cast<const E2*>(&v));
}



template <typename E1, typename T, size_t N>
MinExpression<E1, ScalarExpression<T, N>, T, N>
operator-(Expression<E1, T, N> const& u, const T& v) {
	return MinExpression<E1, ScalarExpression<T, N>, T, N>(*static_cast<const E1*>(&u), *new ScalarExpression<T, N>(v));
}

template <typename E1, typename T, size_t N>
MinExpression<ScalarExpression<T, N>, E1, T, N>
operator-(const T& u, Expression<E1, T, N> const& v) {
	return MinExpression<ScalarExpression<T, N>, E1, T, N>(*new ScalarExpression<T, N>(u), *static_cast<const E1*>(&v));
}

template <typename E1, typename T, size_t N>
MulExpression<E1, T, N>
operator*(Expression<E1, T, N> const& u, const T& v) {
	return MulExpression<E1, T, N>(*static_cast<const E1*>(&u), v);
}

template <typename E1, typename T, size_t N>
MulExpression<E1, T, N>
operator*(const T& u, Expression<E1, T, N> const& v) {
	return MulExpression<E1, T, N>(*static_cast<const E1*>(&v), u);
}



template <typename E1, typename T, size_t N>
DivExpression<E1, T, N>
operator/(Expression<E1, T, N> const& u, const T& v) {
	return DivExpression<E1, T, N>(*static_cast<const E1*>(&u), v);
}


template<typename V>
struct Vectorize {
	using T = typename V::element_type;
	template<func<T> f >
	struct inner {
		template<typename E>
		FuncExpression<E, T, V::size(), f> operator()(const E& e) {
			return FuncExpression < E, T, V::size(), f >(e);
		}
	};
};

#endif