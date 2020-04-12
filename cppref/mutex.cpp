#include "mutex.h"

namespace mutex {
std::mutex printMutex;
void print(const std::string& s) {
	std::lock_guard<std::mutex> l(printMutex);
	for (auto c : s) {
		std::cout.put(c);
	}
	std::cout << std::endl;
}

void run() {
	auto f1 =
	    std::async(std::launch::async, print, "Hello From a first thread");
	auto f2 =
	    std::async(std::launch::async, print, "Hello From a second thread");
	print("Hello from main thread");
	f1.get();
	f2.get();
}

}  // namespace mutex
