#include <cctype>

int main() {
	std::string s("Hello World!!!");
	decltype(s.size()) pcnt = 0;

	for (auto c : s)
		if (std::ispunct(c)) ++pcnt;
	std::cout << pcnt << " punctuation chars in " << s << std::endl;

	for (auto &c : s) c = std::toupper(c);
	std::cout << s << std::endl;
}
