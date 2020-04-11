#include "multiset.h"

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

namespace multiset {

void run() {
	std::cout << "----- <std::multiset> -----" << std::endl;

	std::multiset<std::string> m;
	for (auto s : {"Braunschweig", "Hanover", "Frankfurt", "New York",
		       "Chicago", "Toronto", "Paris", "Frankfurt"}) {
		m.insert(s);
	}
	m.insert({"London", "Munich", "Hanover", "Braunschweig"});
	print_ms(m);

	std::cout << "Convert to a set" << std::endl;
	std::set<std::string> s(m.begin(), m.end());
	print_ms(s);

	std::cout << "Convert to a vec" << std::endl;
	std::vector<std::string> vec(m.begin(), m.end());
	std::sort(vec.begin(), vec.end());
	print_ms(vec);

	std::cout << "Convert to a unorderd_set" << std::endl;
	std::unordered_set<std::string> us(m.begin(), m.end());
	print_ms(us);
	std::cout << "----- </std::multiset> -----" << std::endl;
}

}  // namespace multiset

