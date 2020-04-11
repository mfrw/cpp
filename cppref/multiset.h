#include <iostream>

namespace multiset {

void run();

template <class T>
void print_ms(T& m) {
	for (auto it = m.begin(); it != m.end(); ++it) {
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
}
}  // namespace multiset
