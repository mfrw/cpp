#include <iostream>
#include <stack>

namespace stack {
void run() {
	std::stack<int> s;
	s.push(2);
	s.push(3);
	s.push(1);

	std::cout << s.size() << ": elements on the stack\n" << std::endl;
}

}  // namespace stack
