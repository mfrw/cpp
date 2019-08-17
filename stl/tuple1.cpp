#include <complex>
#include <iostream>
#include <string>
#include <tuple>
#include "printtuple.hpp"

using namespace std;

int main(int argc, char *argv[]) {
	tuple<string, int, int, complex<double>> t;
	tuple<int, float, string> t1(41, 6.3, "mfrw");

	cout << get<0>(t1) << " ";
	cout << get<1>(t1) << " ";
	cout << get<2>(t1) << " ";
	cout << endl;

	auto t2 = make_tuple(22, 44, "mfrw");

	get<1>(t1) = get<1>(t2);

	if (t1 < t2) {
		t1 = t2;
	}

	cout << get<1>(t1) << endl;
	cout << t1 << endl;

	return 0;
}
