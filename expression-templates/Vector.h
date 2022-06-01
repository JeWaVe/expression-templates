#ifndef __DEF_VECTOR__
#define __DEF_VECTOR__

#ifdef _MSC_VER
#define ALIGNED(x) __declspec(align(x))
#define INLINED __forceinline 
#else 
#define ALIGNED(x) __attribute__((aligned(x)))
#define INLINED __attribute__((always_inline))  
#endif

template<typename, typename, size_t> struct Expression;
template<size_t, typename, typename, size_t> struct vector_constructor_loop_helper;
template<size_t, typename, size_t> struct vector_constructor_loop_helper2;

template<typename T, size_t N>
struct ALIGNED(64) Vector : public Expression<Vector<T, N>, T, N> {
	typedef T element_type;
	static constexpr size_t size() {
		return N;
	}
	template<typename, typename, size_t> friend struct Expression;
private:
	T data[N];

	template<size_t i>
	T _get() const {
		return data[i];
	}

public:
	INLINED
	Vector(std::initializer_list<T> e) {
		vector_constructor_loop_helper2<0, T, N>::func(*this, e.begin());
	}

	template<size_t i>
	void set(const T& val) {
		data[i] = val;
	}

	T operator[](size_t i) const {
		return data[i];
	}

	T& operator[](size_t i) {
		return data[i];
	}

	template<typename V>
	INLINED
	Vector(const Expression<V, T, N>& e) {
		vector_constructor_loop_helper<0, V, T, N>::func(*this, e);
	}
};

template<size_t i, typename V, typename T, size_t N>
struct vector_constructor_loop_helper {
	INLINED
	static void func(Vector<T, N>& v, const Expression<V, T, N>& e) {
		v.template set<i>(e.template get<i>());
		vector_constructor_loop_helper<i + 1, V, T, N>::func(v, e);
	}
};

template<typename V, typename T, size_t N>
struct vector_constructor_loop_helper<N, V, T, N> {
	static void func(Vector<T, N>& v, const Expression<V, T, N>& e) {}
};


template<size_t i, typename T, size_t N>
struct vector_constructor_loop_helper2 {
	INLINED
	static void func(Vector<T, N>& v, typename std::initializer_list<T>::iterator it) {
		v.template set<i>(*it);
		vector_constructor_loop_helper2<i + 1, T, N>::func(v, it + 1);
	}
};

template<typename T, size_t N>
struct vector_constructor_loop_helper2<N, T, N> {
	static void func(Vector<T, N>& v, typename std::initializer_list<T>::iterator it) {}
};

#endif