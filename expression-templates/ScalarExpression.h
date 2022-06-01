#ifndef __DEF_SCALAR__
#define __DEF_SCALAR__


template<typename V, typename T, size_t N>
struct Expression;

template<typename T, size_t N>
struct ScalarExpression : Expression<ScalarExpression<T, N>, T, N> {
	template<typename, typename, size_t> friend struct Expression;
private:
	T _d;

	template<size_t i>
	T _get() const {
		return _d;
	}

public:
	ScalarExpression(const T& d) : _d(d) {}
};

#endif