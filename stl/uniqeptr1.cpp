#include <dirent.h>
#include <cerrno>
#include <cstring>
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class DirCloser {
       public:
	void operator()(DIR* dp) {
		if (closedir(dp) != 0) {
			std::cerr << "OOPS: closedir() failed" << std::endl;
		}
	}
};

int main(int argc, char* argv[]) {
	unique_ptr<DIR, DirCloser> pDir(opendir("."));

	struct dirent* dp;
	while ((dp = readdir(pDir.get())) != nullptr) {
		string filename(dp->d_name);
		std::cout << "process " << filename << std::endl;
	}
	return 0;
}
