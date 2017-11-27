#include <iostream>
#include <vector>
#include <list>
#include <string>

template <typename ITERATOR_TYPE, typename VALUE_TYPE>
ITERATOR_TYPE find(ITERATOR_TYPE beg, ITERATOR_TYPE end, VALUE_TYPE v) {
    for (auto it = beg; it != end; ++it) {
        if (*it == v) {
            return it;
        }
    }
    return end;
}

int main() {
    std::vector<int> iv = {0, 1, 2, 3, 4};
    std::vector<std::string> sv = {"one", "two", "three", "four", "five"};

    std::cout << *find(iv.begin(), iv.end(), 2) << std::endl;
    std::cout << *find(sv.begin(), sv.end(), "five") << std::endl;
    
    return 0;
}
