#include "String.h"

#include <vector>
#include <iostream>

int main() {
    std::cout << "input the number of elements will be pushed into the vector: ";
    int number;
    int non;
    std::cin >> number;
    std::vector<String> sv;    
    for (auto i = 0; i != number; ++i) {
        sv.push_back("");
        // std::cin >> non;
    }
    
    return 0;
}
