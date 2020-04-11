#include "set.h"

#include <iostream>
#include <set>
#include <string>

namespace set {
void run() {
	std::set<std::string> s;
	s.insert("first");
	s.insert("second");
	s.insert("third");
	s.insert("first");

	std::cout << "Set Size = " << s.size() << std::endl;

	for (auto& it : s) std::cout << it << ' ';
	std::cout << std::endl;
}
}  // namespace set
