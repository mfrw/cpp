#include "vector.h"

#include <iostream>
#include <vector>

namespace vector {
void run() {
	std::cout << "----- <std::vector> -----" << std::endl;
	std::vector<int> v = {7, 5, 16, 8};
	v.push_back(25);
	v.push_back(13);
	for (int n : v) {
		std::cout << n << ' ';
	}
	std::cout << std::endl;

	std::vector<int> coll;
	for (int i = 0; i < 6; ++i) {
		coll.push_back(i);
	}

	for (int n : coll) std::cout << n << ' ';
	std::cout << std::endl;
	std::cout << "----- </std::vector> -----" << std::endl;
}
}  // namespace vector
