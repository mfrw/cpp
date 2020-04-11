#include "async.h"

#include <chrono>
#include <exception>
#include <future>
#include <iostream>
#include <random>
#include <thread>

namespace async {
int doSomething(char c) {
	std::default_random_engine dre(c);
	std::uniform_int_distribution<int> id(10, 1000);

	for (int i = 0; i < 10; ++i) {
		std::this_thread::sleep_for(std::chrono::milliseconds(id(dre)));
		std::cout.put(c).flush();
	}
	return c;
}
int func1() { return doSomething('.'); }
int func2() { return doSomething('+'); }
int func3(char c) { return doSomething(c); }

void run() {
	std::cout << "starting func1() in bg"
		  << " and func2() in fg:" << std::endl;
	std::future<int> result1(std::async(func1));
	std::future<int> result2(std::async(func1));
	std::future<int> result3(std::async(func1));
	std::future<int> result4(std::async(func1));
	std::future<int> res(std::async([]() -> int { return func3('x'); }));
	std::future<int> res1(std::async(std::launch::deferred, func3, 'y'));
	int result5 = func2();
	int result = result1.get() + result2.get() + result3.get() +
		     result4.get() + result5 + res.get() + res1.get();
	std::cout << "\nresult of funcs(): " << result << std::endl;
}

}  // namespace async
