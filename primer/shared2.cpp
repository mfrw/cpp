#include <algorithm>
#include <cstdio>
#include <fstream>
#include <functional>
#include <iostream>
#include <memory>
#include <string>

class FileDeleter {
       private:
	std::string filename;

       public:
	FileDeleter(const std::string& fn) : filename(fn) {}
	void operator()(std::ofstream* fp) {
		fp->close();
		// std::remove(filename.c_str());
		std::cout << "Closed: " << filename << std::endl;
	}
};

int main() {
	std::shared_ptr<std::ofstream> fp(new std::ofstream("tmpfile.txt"),
					  FileDeleter("tmpfile.txt"));
	int num[5] = {4, 3, 6, 7, 12};
	std::sort(std::begin(num), std::end(num));

	for (auto it = std::begin(num); it != std::end(num); ++it)
		*fp << *it << std::endl;
	return 0;
}
