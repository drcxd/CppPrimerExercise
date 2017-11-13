#include "c14e35.cc"

#include <vector>
#include <string>

int main() {
    StringReader sr;
    std::vector<std::string> sv;
    std::string temp;
    for (unsigned i = 0; i < 5; ++i) {
        temp = sr();
        sv.push_back(temp);
    }
    for (auto &i : sv) {
        std::cout << i << std::endl;
    }
    return 0;
}
