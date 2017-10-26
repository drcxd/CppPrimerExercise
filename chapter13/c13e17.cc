#include <iostream>
#include <random>

// Exercise 14 Version
// struct numbered {
//     numbered() { std::random_device rd; mysn = rd(); }
//     int mysn;
// };

// void f(numbered s) { std::cout << s.mysn << std::endl; }

// Exercise 15 Version
// struct numbered {
//     numbered() { std::random_device rd; mysn = rd(); }
//     numbered(const numbered &) { std::random_device rd; mysn = rd(); }
//     int mysn;
// };

// void f(numbered s) { std::cout << s.mysn << std::endl; }

// Exercise 16 Version
struct numbered {
    numbered() { std::random_device rd; mysn = rd(); }
    numbered(const numbered &) { std::random_device rd; mysn = rd(); }
    int mysn;
};

void f(const numbered &s) { std::cout << s.mysn << std::endl; }

int main() {
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
    std::cout << a.mysn << std::endl;
    std::cout << b.mysn << std::endl;
    std::cout << c.mysn << std::endl;
    return 0;
}
