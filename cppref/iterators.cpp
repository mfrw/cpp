#include "iterators.h"

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <set>
#include <vector>

namespace iterators {
template <class T>
void print_col(T& t) {
	for (auto e : t) std::cout << e << ' ';
	std::cout << std::endl;
}

void run() {
	std::list<int> coll1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::vector<int> coll2;
	print_col<std::list<int>>(coll1);

	std::copy(coll1.cbegin(), coll1.cend(), std::back_inserter(coll2));
	print_col<std::vector<int>>(coll2);

	std::deque<int> coll3;
	std::copy(coll1.cbegin(), coll1.cend(), std::front_inserter(coll3));
	print_col(coll3);

	std::set<int> coll4;
	std::copy(coll1.cbegin(), coll1.cend(),
		  std::inserter(coll4, coll4.begin()));
	print_col(coll4);
}

}  // namespace iterators
