#include <forward_list>
#include <iostream>

namespace fwd_list {
void run() {
	std::forward_list<int> f1;
	std::forward_list<int> f2;

	f1.assign({1, 2, 3, 4});
	f2.assign(5, 10);
	std::cout << "The lements of f1: ";
	for (int& a : f1) std::cout << a << ' ';
	std::cout << std::endl;

	std::cout << "The elements of f2: ";
	for (int& b : f2) std::cout << b << ' ';
	std::cout << std::endl;
}
}  // namespace fwd_list
