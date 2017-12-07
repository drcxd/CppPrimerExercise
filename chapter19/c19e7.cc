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
    Base *bp = new Derived2();
    // Base *bp = new Derived1();
    try {
        Derived1 &r = dynamic_cast<Derived1 &>(*bp);
        std::cout << "Success\n";
    } catch (std::bad_cast e) {
        std::cout << "Fail\n";
    }
    return 0;
}
