#ifndef __DEF_FUNCEXPR__
#define __DEF_FUNCEXPR__

template<typename V, typename T, size_t N>
struct Expression;

template<typename T>
using func = T(*)(const T&);

template<typename E, typename T, size_t N, func<T> f>
struct FuncExpression : Expression<FuncExpression<E, T, N, f>, T, N> {
	template<typename, typename, size_t> friend struct Expression;
private:
	E _e;

	template<size_t i>
	T _get() const {
		return f(_e.template get<i>());
	}

public:
	FuncExpression(const E& e) : _e(e) {}
};



#endif