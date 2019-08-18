#include <chrono>
#include "clock.hpp"

int main(int argc, char *argv[]) {
	std::cout << " system_clock: " << std::endl;
	printClockData<std::chrono::system_clock>();

	std::cout << "\nhigh_resolution_clock: " << std::endl;
	printClockData<std::chrono::high_resolution_clock>();

	std::cout << "\nstead_clock: " << std::endl;
	printClockData<std::chrono::steady_clock>();

	return 0;
}
