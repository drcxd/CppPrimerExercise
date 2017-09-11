#include <memory>
#include <iostream>
#include <vector>

std::vector<int> *create_vector() {
    return new std::vector<int>;
}

std::vector<int> *read(std::vector<int> *v) {
    int value;
    std::cout << "input a number: ";
    std::cin >> value;
    while (std::cin)  {
        v->push_back(value);
        std::cout << "input a number: ";
        std::cin >> value;
    }
    
    return v;
}

std::vector<int> *print(std::vector<int> *v) {
    for (auto i : *v) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return v;
}

int main() {
    std::vector<int> *vp = create_vector();
    read(vp);
    print(vp);
    delete vp;
    vp = nullptr;
    
    return 0;
}
