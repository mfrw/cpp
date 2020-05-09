#include "array.h"

namespace array {
std::vector<int> spiralOrder(const std::vector<std::vector<int>> &v) {
	std::vector<int> result;
	int col = v[0].size();
	int row = v.size();
	result.reserve(col * row);

	int top = 0;
	int bottom = row - 1;
	int right = col - 1;
	int left = 0;
	enum direction {
		LeftRight,
		TopBottom,
		RightLeft,
		BottomTop,
	};

	direction dir = LeftRight;
	while (top <= bottom && left <= right) {
		switch (dir) {
			case LeftRight:
				for (int i = left; i <= right; ++i)
					result.push_back(v[top][i]);
				top++;
				dir = TopBottom;
				break;
			case TopBottom:
				for (int i = top; i <= bottom; ++i)
					result.push_back(v[i][right]);
				right--;
				dir = RightLeft;
				break;
			case RightLeft:
				for (int i = right; i >= left; --i)
					result.push_back(v[bottom][i]);
				bottom--;
				dir = BottomTop;
				break;
			case BottomTop:
				for (int i = bottom; i >= top; --i)
					result.push_back(v[i][left]);
				left++;
				dir = LeftRight;
				break;
		}
	}
	return result;
}

int coverPoints(const std::vector<int> &x, const std::vector<int> &y) {
	int steps = 0;
	for (int i = 0; i < x.size() - 1; ++i)
		steps += std::max(std::abs(x[i + 1] - x[i]),
				  std::abs(y[i + 1] - y[i]));
	return steps;
}

std::vector<int> addOne(const std::vector<int> &v) {
	std::vector<int> result(v.begin(), v.end());
	bool carry = false;
	for (int i = result.size() - 1; i >= 0; --i) {
		if (i == result.size() - 1) {
			if (result[i] == 9) {
				result[i] = 0;
				carry = true;
			} else {
				result[i]++;
			}
			continue;
		}
		if (carry) {
			if (result[i] == 9) {
				result[i] = 0;
				carry = true;
			} else {
				result[i]++;
				carry = false;
			}
		}
	}
	if (carry) result.insert(result.begin(), 1);
	while (result[0] == 0) result.erase(result.begin());
	return result;
}

void run() {
	std::vector<std::vector<int>> m{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	auto got = spiralOrder(m);
	std::vector<int> want{1, 2, 3, 6, 9, 8, 7, 4, 5};

	/*check */
	if (got.size() != want.size()) {
		std::cout << "Failed to print spirally" << std::endl;
		return;
	}
	if (std::equal(got.begin(), got.end(), want.begin())) {
		std::cout << "Yayay !!!.. spiral done" << std::endl;
	} else {
		std::cout << "Failed to print spirally" << std::endl;
	}
	std::vector<std::vector<int>> t1{{1, 2}, {3, 4}, {5, 6}};
	auto got1 = spiralOrder(t1);
	std::vector<int> want1{1, 2, 4, 6, 5, 3};
	if (std::equal(got1.begin(), got1.end(), want1.begin())) {
		std::cout << "Yayay !!!.. spiral done" << std::endl;
	} else {
		std::cout << "Failed to print spirally" << std::endl;
		for (const auto &i : got1) std::cout << i << ' ';
		std::cout << std::endl;
	}

	std::vector<int> x{0, 1, 1};
	std::vector<int> y{0, 1, 2};
	auto steps = coverPoints(x, y);
	std::cout << "Min steps: " << steps << std::endl;

	std::vector<int> ax{0, 0, 9, 9, 9};
	auto got2 = addOne(ax);
	auto want2 = {1, 0, 0, 0};
	if (std::equal(got2.begin(), got2.end(), want2.begin())) {
		std::cout << "Yaya added one nicely" << std::endl;
	} else {
		for (const auto &i : got2) std::cout << i << ' ';
		std::cout << std::endl;
	}
}

}  // namespace array
