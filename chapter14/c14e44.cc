#include <functional>
#include <iostream>
#include <map>
#include <string>

struct add {
    int operator()(int i, int j) { return i + j; }
};

int sub(int i, int j) {
    return i - j;
}

int main() {
    auto mul = [] (int i, int j) { return i * j; };
    
    std::map<std::string, std::function<int (int, int)>> operators = {
        {"+", add()},
        {"-", sub},
        {"*", mul},
        {"/", std::divides<int>()}
    };
    
    // operators.insert("+", add());
    // operators.insert("-", sub);
    // operators.insert("*", mul);
    // operators.insert("/", std::divides<int>);

    std::cout << operators["+"](1, 2) << std::endl;
    std::cout << operators["-"](15, 10) << std::endl;
    std::cout << operators["*"](22, 10) << std::endl;
    std::cout << operators["/"](33, 11) << std::endl;

    return 0;
}
