#include <iostream>

template <typename T> void f(T) { std::cout << "a is called\n"; }            // (a)
template <typename T> void f(const T *) { std::cout << "b is called\n"; }    // (b)
template <typename T> void g(T) { std::cout << "c is called\n"; }            // (c)
template <typename T> void g(T *) { std::cout << "d is called\n"; }          // (d)

int main() {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;
    g(42);             // (c) is called
    g(p);              // (d) is called
    g(ci);             // (c) is called
    g(p2);             // (d) is called
    f(42);             // (a) is called
    f(p);              // (a) is called
    f(ci);             // (a) is called
    f(p2);             // (b) is called
    return 0;
}
