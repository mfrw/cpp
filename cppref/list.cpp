#include <algorithm>
#include <iostream>
#include <list>

namespace list {
void run() {
	std::list<int> l = {7, 5, 16, 8};
	l.push_front(25);
	l.push_back(13);
	auto it = std::find(l.begin(), l.end(), 16);
	if (it != l.end()) {
		l.insert(it, 42);
	}
	for (int n : l) {
		std::cout << n << ' ';
	}
	std::cout << std::endl;
}
}  // namespace list
