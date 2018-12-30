#include <iostream>
#include <string>

int main() {
	std::string hex("0123456789ABCDEF");
	std::cout << "Enter a digit" << std::endl;
	std::string res;

	std::string::size_type n;
	while (std::cin >> n)
		if (n < hex.size()) {
			res += hex[n];
		}
	std::cout << "Your hex nr is: " << res << std::endl;
}
