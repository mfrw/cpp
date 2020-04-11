#include <cstddef>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

namespace sharedptr {
class Person;
class FileDeleter;
std::shared_ptr<Person> initFamily(const std::string& name);

void simple_use();
void run();
void family();

}  // namespace sharedptr

class sharedptr::FileDeleter {
       private:
	std::string filename_;

       public:
	FileDeleter(const std::string& fn) : filename_(fn) {
		std::cout << "Initialized FileDeleter with File: " << filename_
			  << std::endl;
	}
	void operator()(std::ofstream* fp) {
		std::cout << "All handlers of the file are done, closing and "
			     "removing: "
			  << filename_ << std::endl;
		fp->close();
		std::remove(filename_.c_str());
	}
};

class sharedptr::Person {
       public:
	std::string name;
	std::shared_ptr<Person> mother;
	std::shared_ptr<Person> father;
	std::vector<std::weak_ptr<Person>> kids;

	Person(const std::string& n, std::shared_ptr<Person> m = nullptr,
	       std::shared_ptr<Person> f = nullptr)
	    : name(n), mother(m), father(f) {}
	~Person() { std::cout << "delete " << name << std::endl; }
};
