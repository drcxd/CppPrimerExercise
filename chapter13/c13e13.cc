#include <iostream>
#include <vector>

struct X {
    X() { std::cout << "X()" << std::endl; }
    ~X() { std::cout << "~X()" << std::endl; }
    X(const X &) { std::cout << "X(const X &)" << std::endl; }
    X &operator=(const X &) { std::cout << "operator=()(const X &)" << std::endl; return *this; }
};

void func1(X &) {
    std::cout << "func1 reference" << std::endl;
}

void func2(X) {
    std::cout << "func2 no reference" << std::endl;
}

int main() {
    X obj1;
    func1(obj1);
    func2(obj1);
    X *p1 = new X;
    std::vector<X> vec;
    vec.push_back(obj1);
    delete p1;
}
