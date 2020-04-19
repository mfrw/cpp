#include "fibo.h"

namespace fibo {
int fib(int n, std::map<int, int>& m) {
	auto pos = m.find(n);
	if (pos != m.end()) {
		std::cout << "Used the cache for: " << n << std::endl;
		return m[n];
	}
	auto res = fib(n - 2, m) + fib(n - 1, m);
	m[n] = res;
	return res;
}

void run() {
	std::map<int, int> m{{0, 1}, {1, 1}};  // initialize the map
	int n = 50;
	auto r = fib(n, m);
	std::cout << "fib(" << n << ") => " << r << std::endl;
	std::cout << "Map Size: " << m.size() << std::endl;
	return;
}

}  // namespace fibo
