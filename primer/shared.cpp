#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

int main() {
	shared_ptr<string> pNico(new string("nico"), [](string *p) {
		cout << "delete " << *p << endl;
		delete p;
	});
	shared_ptr<string> pJutta(new string("jutta"));

	(*pNico)[0] = 'N';
	pJutta->replace(0, 1, "J");

	vector<shared_ptr<string>> whoMadeCoffee;
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);

	for (auto ptr : whoMadeCoffee) {
		cout << *ptr << " ";
	}
	cout << endl;

	*pNico = "Nicolai";

	for (auto ptr : whoMadeCoffee) {
		cout << *ptr << " ";
	}
	cout << endl;
	cout << "use_count: " << whoMadeCoffee[2].use_count() << endl;
	whoMadeCoffee.resize(2);
	cout << "use_count: " << pNico.use_count() << endl;
}
