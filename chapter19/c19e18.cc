#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <functional>

int count_empty(const std::vector<std::string> &sv) {
    using std::placeholders::_1;
    return count_if(sv.cbegin(), sv.cend(), std::bind(&std::string::empty, _1));
}

int main() {
    std::vector<std::string> sv = {"", "one", "", "two", "", "three"};
    std::cout << count_empty(sv) << std::endl;
    return 0;
}
