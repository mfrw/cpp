#ifndef MAP_H_CYNHKBXN
#define MAP_H_CYNHKBXN

#include <iostream>
#include <map>

namespace map {
class RuntimeStringCmp;
void map_find();
void count_rands();
void count_words(std::istream& in, std::map<std::string, int>&);
void run();
void fillAndPrint(std::map<std::string, std::string, RuntimeStringCmp>& coll);
}  // namespace map

class map::RuntimeStringCmp {
       public:
	enum cmp_mode { normal, nocase };

       private:
	const cmp_mode mode;

	static bool nocase_compare(char c1, char c2) {
		return std::toupper(c1) < std::toupper(c2);
	}

       public:
	RuntimeStringCmp(cmp_mode m = normal) : mode(m) {}

	bool operator()(const std::string& s1, const std::string& s2) const {
		if (mode == normal) {
			return s1 < s2;
		} else {
			return std::lexicographical_compare(
			    s1.begin(), s1.end(), s2.begin(), s2.end(),
			    nocase_compare);
		}
	}
};

#endif /* end of include guard: MAP_H_CYNHKBXN */
