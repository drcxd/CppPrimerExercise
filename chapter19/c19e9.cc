#include <iostream>
#include <typeinfo>

using std::cout;
using std::endl;

struct Base {};
struct Derived: public Base {};

int main() {
    cout << typeid(int).name() << endl
         << typeid(double).name() << endl
         << typeid(char).name() << endl
         << typeid(float).name() << endl
         << typeid(Base).name() << endl
         << typeid(Base*).name() << endl
         << typeid(Derived).name() << endl
         << typeid(Derived*).name() << endl;
    return 0;
}
