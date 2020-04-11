#include "sharedptr.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace sharedptr {
void family() {
	std::shared_ptr<Person> p = initFamily("nico");
	std::cout << "nicos family exists" << std::endl;
	std::cout << "- nico is shared " << p.use_count() << " time"
		  << std::endl;
	std::cout << "- name of 1st kid of nico's mom: "
		  << p->mother->kids[0].lock()->name << std::endl;

	p = initFamily("jim");
	std::cout << "Jims fanily exists" << std::endl;
}

void create_delete_file(std::string fn) {
	std::string text = "this is some random text we want in a file";
	{
		std::shared_ptr<std::ofstream> fp(new std::ofstream(fn),
						  FileDeleter(fn));
		*fp << text << std::endl;
		std::cout << "written to file" << std::endl;
		char t;
		std::cin >> t;
	}
	std::cout << "The tempfile should be destroyed now" << std::endl;
}

void simple_use() {
	std::shared_ptr<std::string> pNico(new std::string("nico"));
	std::shared_ptr<std::string> pJutta{new std::string("jutta")};
	(*pNico)[0] = 'N';
	pJutta->replace(0, 1, "J");

	std::vector<std::shared_ptr<std::string>> whoMadeCoffee;
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);

	for (auto ptr : whoMadeCoffee) {
		std::cout << *ptr << ' ';
	}
	std::cout << std::endl;
	std::cout << "use count: " << whoMadeCoffee[0].use_count() << std::endl;
}

void run() {
	simple_use();
	create_delete_file("tempfile.txt");
	family();
}

}  // namespace sharedptr

std::shared_ptr<sharedptr::Person> sharedptr::initFamily(
    const std::string& name) {
	std::shared_ptr<sharedptr::Person> mom(
	    new sharedptr::Person(name + "'s mom"));
	std::shared_ptr<sharedptr::Person> dad(
	    new sharedptr::Person(name + "'s dad"));
	std::shared_ptr<sharedptr::Person> kid(
	    new sharedptr::Person(name, mom, dad));
	mom->kids.push_back(kid);
	dad->kids.push_back(kid);
	return kid;
}
