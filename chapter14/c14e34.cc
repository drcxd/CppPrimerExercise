#include <iostream>

class Select {
public:
    int operator()(const bool condition, int exp1, int exp2) {
        return condition ? exp1 : exp2;
    }
};

int main() {
    Select select;
    int a, b;
    std::cin >> a >> b;
    std::cout << select(a > b, a, b) << std::endl;
    return 0;
}
