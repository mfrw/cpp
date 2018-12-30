#include <iostream>

int reused = 42;

int main(int argc, char *argv[]) {
	int unique = 0;
	std::cout << reused << " " << unique << std::endl;
	int reused = 0;
	std::cout << reused << " " << unique << std::endl;
	std::string s;
	return 0;
}
