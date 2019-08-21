#include <iostream>
#include <list>

int main(int argc, char *argv[]) {
	std::list<char> coll;

	for (char i = 'a'; i <= 'z'; ++i) {
		coll.push_back(i);
	}
	for (auto pos = coll.begin(); pos != coll.end(); ++pos)
		std::cout << *pos << ' ';
	std::cout << std::endl;

	return 0;
}
