#include<algorithm>
#include<iostream>
#include<set>
#include<stdio.h>
#include<stdlib.h>
#include<vector>


main(int argc, char const *argv[]) {
    int64_t in = 0;

    std::vector<int64_t> input;
    std::set<int64_t> frequencies;

    while(!std::cin.eof()) {
        std::cin >> in;
        input.push_back(in);
    }
    
    return 0;
}
