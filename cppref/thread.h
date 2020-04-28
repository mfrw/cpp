#ifndef THREAD_H_R9DYQZAV
#define THREAD_H_R9DYQZAV

#include <exception>
#include <iostream>
#include <memory>
#include <stack>
#include <thread>

namespace thread {
class background_task {
       public:
	void operator()() const {
		std::cout << "Hello world from bg task" << std::endl;
	}
};

template <typename T>
class threadsafe_stack;
struct empty_stack : std::exception {
	const char* what() const throw();
};

void run();
}  // namespace thread

#endif /* end of include guard: THREAD_H_R9DYQZAV */
