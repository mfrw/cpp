#include <chrono>
#include <ctime>
#include <iostream>
#include <string>

std::string asString(const std::chrono::system_clock::time_point& tp) {
	std::time_t t = std::chrono::system_clock::to_time_t(tp);
	std::string ts = std::ctime(&t);
	ts.resize(ts.size() - 1);
	return ts;
}

int main() {
	std::chrono::system_clock::time_point tp;
	std::cout << "epoch: " << asString(tp) << std::endl;

	tp = std::chrono::system_clock::now();
	std::cout << "now: " << asString(tp) << std::endl;

	tp = std::chrono::system_clock::time_point::min();
	std::cout << "min: " << asString(tp) << std::endl;

	tp = std::chrono::system_clock::time_point::max();
	std::cout << "max: " << asString(tp) << std::endl;
}
