#include <atomic>
#include <iostream>
#include <thread>

std::atomic<int> a(0);

void adder() {
	for (int i = 0; i < 400000000; ++i) {
		a.fetch_add(1);
	}
}

int main() {
	std::thread t(adder);
	for (int i = 0; i < 100000000; ++i) {
		a.fetch_add(1);
	}
	t.join();
	std::cout << a << std::endl;
}

