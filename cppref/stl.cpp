#include "stl.h"

#include <future>
#include <vector>

int main() {
	std::vector<void (*)()> fns;

	fns.push_back(array::run);
	fns.push_back(vector::run);
	fns.push_back(deque::run);
	fns.push_back(fwd_list::run);
	fns.push_back(list::run);
	fns.push_back(set::run);
	fns.push_back(map::run);
	fns.push_back(stack::run);
	fns.push_back(sharedptr::run);
	fns.push_back(multiset::run);
	fns.push_back(iterators::run);
	fns.push_back(async::run);
	fns.push_back(mutex::run);

	std::vector<std::future<void>> func_futs;
	for (auto fn : fns) func_futs.push_back(std::async(fn));

	for (auto& ft : func_futs) ft.get();

	mutex::run();
	allocator::run();
	fibo::run();
	thread::run();
}
