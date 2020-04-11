#include "map.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <random>
#include <string>
#include <utility>

namespace map {
void map_find() {
	std::map<std::string, int> m{{"one", 1}, {"two", 2}};
	m.insert({"three", 3});
	auto pos = m.find("three");
	if (pos != m.end()) {
		std::cout << "Found elt: " << pos->first
			  << " value: " << pos->second << ' ' << std::endl;
	}
}
void count_words(std::istream& in, std::map<std::string, int>& m) {
	std::string s;
	while (in >> s) {
		++m[s];
	}
}
void count_rands() {
	std::map<int, int> m;
	std::random_device r;
	std::default_random_engine engine(r());
	for (int i = 0; i < 10000; ++i) {
		m[engine() % 100]++;
	}
	std::cout << "Total elements in map: " << m.size() << std::endl;
	int max_val = -1;
	int max_num;
	for (const auto& [num, val] : m) {
		if (val > max_val) {
			max_num = num;
			max_val = val;
		}
	}
	std::cout << "Nr: " << max_num << " repeats: " << max_val << std::endl;
}

void run() {
	std::map<int, std::string> m;
	m.insert({1, "one"});
	std::pair<int, std::string> p = std::make_pair(17, "seventeen");
	m.insert(p);
	m[2] = "two";

	for (const auto& [num, str] : m)
		std::cout << num << ": " << str << '\n';
	std::cout << std::endl;
	count_rands();

	// count all chars in a file
	std::string s = "test.txt";
	std::ifstream in(s);
	if (!in) {
		std::cout << "Error opening File: " << s << std::endl;
		return;
	}
	std::map<std::string, int> wm;
	count_words(in, wm);
	for (auto i = wm.begin(); i != wm.end(); ++i) {
		std::cout << i->first << " occurred " << i->second << " times\n"
			  << std::endl;
	}
	map_find();

	RuntimeStringCmp ignorecase((RuntimeStringCmp::nocase));
	RuntimeStringCmp normalcase((RuntimeStringCmp::normal));
	std::map<std::string, std::string, RuntimeStringCmp> collection(
	    ignorecase);

	std::map<std::string, std::string, RuntimeStringCmp> coll_copy(
	    collection.begin(), collection.end());

	fillAndPrint(collection);
	std::cout << "------ unorderd -------" << std::endl;
	fillAndPrint(coll_copy);

	std::cout << "---- std::inserter ----" << std::endl;
	std::map<std::string, std::string, RuntimeStringCmp> coll_copy2(
	    normalcase);
	std::copy(coll_copy.begin(), coll_copy.end(),
		  std::inserter(coll_copy2, coll_copy2.begin()));
	fillAndPrint(coll_copy2);
}

}  // namespace map

void map::fillAndPrint(
    std::map<std::string, std::string, map::RuntimeStringCmp>& coll) {
	coll["Deushchland"] = "Germany";
	coll["deutsch"] = "German";
	coll["Haken"] = "snag";
	coll["arbeiten"] = "work";
	coll["Hund"] = "dog";
	coll["gehen"] = "go";
	coll["Unternehmen"] = "enterprise";
	coll["unternehmen"] = "undertake";
	coll["gehen"] = "walk";
	coll["Bestatter"] = "undertaker";

	std::cout.setf(std::ios::left, std::ios::adjustfield);
	for (const auto& elem : coll) {
		std::cout << std::setw(15) << elem.first << " " << elem.second
			  << std::endl;
	}
}
