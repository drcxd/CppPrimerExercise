#include <functional>
#include <vector>
#include <iostream>
#include <algorithm>

int main() {
    std::vector<int> iv = { 2, 3, 5 };
    int num;
    std::cin >> num;
    std::modulus<int> mod;
    auto p = [&] (int i) { return mod(num, i) == 0; };
    bool divisible = std::any_of(iv.begin(), iv.end(), p);
    std::cout << (divisible ? "Yes" : "No") << std::endl;

    return 0;
}
