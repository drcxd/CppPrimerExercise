#include <iostream>
#include <typeinfo>

struct Base {
    virtual void print() { std::cout << "Base\n"; }
};

struct Derived1 : public Base {
    void print() override { std::cout << "Derived1\n"; }
};

struct Derived2 : public Base {
    void print() override { std::cout << "Derived2\n"; }
};

int main() {
    Base *bp1 = new Derived1();
    Base *bp2 = new Derived2();
    if (typeid(*bp1) == typeid(*bp2)) {
        std::cout << "same type\n";
    } else {
        std::cout << "different type\n";
    }
    if (typeid(*bp1) == typeid(Derived1)) {
        std::cout << "type is Derived1\n";
    } else {
        std::cout << "type is not Derived1\n";
    }
    return 0;
}
