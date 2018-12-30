#include <iostream>
#include <vector>

int main() {
	std::vector<int> v;
	for (int i = 0; i < 100; ++i) {
		v.push_back(i);
	}
	for (auto i = v.begin(); i != v.end(); i++) {
		std::cout << *i << std::endl;
	}
}
