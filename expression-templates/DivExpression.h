#ifndef __DEF_DIVEXPR__
#define __DEF_DIVEXPR__

template<typename V, typename T, size_t N>
struct Expression;

template<typename E, typename T, size_t N>
struct DivExpression : Expression<DivExpression<E, T, N>, T, N> {
	template<typename, typename, size_t> friend struct Expression;
private:
	E _e;
	T _d;

	template<size_t i>
	T _get() const {
		return _e.template get<i>() / _d;
	}

public:
	DivExpression(const E& e, const T& d) : _e(e), _d(d) {}
};


#endif