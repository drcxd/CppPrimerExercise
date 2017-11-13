#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Equal {
public:
    Equal(int i = 0) : value(i) { }
    bool operator()(const int i) const {
        return i == value;
    }
private:
    int value;
};

int main() {
    std::vector<int> iv;
    int temp;
    for (unsigned i = 0; i < 5; ++i) {        
        std::cin >> temp;
        iv.push_back(temp);
    }

    std::replace_if(iv.begin(), iv.end(), Equal(5), 7);
    
    for (auto &i : iv) {
        std::cout << i << std::endl;
    }
    
    return 0;
}
