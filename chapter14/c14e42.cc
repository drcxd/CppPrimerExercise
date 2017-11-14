#include <functional>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::greater<int> gt;
    std::not_equal_to<std::string> neq;
    std::multiplies<int> mul;

    std::vector<int> iv = {1, 2, 3, 4, 1025};
    std::vector<std::string> sv = {"pooh", "one", "two", "three"};
    std::cout << std::count_if(iv.begin(), iv.end(), std::bind(gt, std::placeholders::_1, 1024)) << std::endl;
    std::cout << *std::find_if(sv.begin(), sv.end(), std::bind(neq, std::placeholders::_1, "pooh")) << std::endl;
    std::transform(iv.begin(), iv.end(), iv.begin(), std::bind(mul, std::placeholders::_1, 2));
    for (auto i : iv) {
        std::cout << i << std::endl;
    }

    return 0;
}
