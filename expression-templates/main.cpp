#include "lib.h"

#include <cstdio>

using V = Vector<int, 32>;

int foo(const int& a) {
	return a * 1000;
}

using Vfoo = Vectorize<V>::inner<foo>;

V test(const V& a, const V& b, const V& c) {
	Vfoo vfoo;
	return vfoo(a + 3 * (b + c) / 2);
}

int main(int argc, char* argv[]) {
	V a { 1, 2 };
	V b { 3, 4 };
	V c { 1, 1 };
	V d = test(a, b, c);

	for (int i = 0; i < 2; ++i) {
		printf("got %d expected %d\n", d[i], foo(a[i] + 3 * (b[i] + c[i]) / 2));
	}
}