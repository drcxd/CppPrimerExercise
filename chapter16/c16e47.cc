#include <vector>
#include <utility>
#include <iostream>

template <typename F, typename T1, typename T2>
void flip(F f, T1 &&t1, T2 &&t2) {
    f(std::forward<T2>(t2), std::forward<T1>(t1));
}

void f(int &f1, int f2) {
    ++f1;
}

void g(int &&g1, int g2) {
    std::cout << g1 << " " << g2 << std::endl;
}

int main() {
    int i = 0;
    flip(f, 2, i);
    flip(g, 2, 1);
    std::cout << i << std::endl;
    return 0;
}
