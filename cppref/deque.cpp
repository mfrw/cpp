#include <deque>
#include <iostream>

namespace deque {
void run() {
	std::cout << "----- <std::deque> -----" << std::endl;
	std::deque<int> d = {7, 5, 16, 8};
	d.push_front(13);
	d.push_back(25);

	for (int n : d) std::cout << n << ' ';
	std::cout << std::endl;
	std::cout << "----- </std::deque> -----" << std::endl;
}
}  // namespace deque
