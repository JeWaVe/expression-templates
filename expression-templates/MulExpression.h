#ifndef __DEF_MULEXPR__
#define __DEF_MULEXPR__

template<typename V, typename T, size_t N>
struct Expression;

template<typename E, typename T, size_t N>
struct MulExpression : Expression<MulExpression<E, T, N>, T, N> {
	template<typename, typename, size_t> friend struct Expression;
private:
	E _e;
	T _d;

	template<size_t i>
	T _get() const {
		return _d * _e.template get<i>();
	}

public:
	MulExpression(const E& e, const T& d) : _e(e), _d(d) {}
};


#endif