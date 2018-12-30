#include <iostream>
#include <numeric>
#include <vector>

int main() {
	int x[] = {1, 2, 3, 4, 5, 7, 8, 10, 11};
	std::vector<int> v(std::begin(x), std::end(x));

	int sum = std::accumulate(v.begin(), v.end(), 0);
	std::cout << sum << std::endl;
	return 0;
}
