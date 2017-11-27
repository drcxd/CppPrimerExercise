#include <iostream>

struct Foo {
    int i;
};

template <typename T>
int compare(const T &lhs, const T &rhs) {
    if (lhs < rhs) return 1;
    if (rhs < lhs) return -1;
    return 0;
}

int main() {
    Foo f1, f2;
    std::cout << compare(f1, f2) << std::endl;
    
    return 0;
}
