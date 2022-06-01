#ifndef __DEF_MINEXPR__
#define __DEF_MINEXPR__

template<typename V, typename T, size_t N>
struct Expression;

template<typename El, typename Er, typename T, size_t N>
struct MinExpression : Expression<MinExpression<El, Er, T, N>, T, N> {
	template<typename, typename, size_t> friend struct Expression;
private:
	El _el;
	Er _er;

	template<size_t i>
	T _get() const {
		return _el.template get<i>() - _er.template get<i>();
	}

public:
	MinExpression(const El& l, const Er& r) : _el(l), _er(r) {}
};


#endif