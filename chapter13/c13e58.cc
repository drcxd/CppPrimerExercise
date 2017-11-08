#include <iostream>

class Foo {
public:
    Foo sorted() const & {
        std::cout << "sorted called\n";
        // Foo ret(*this);
        // return ret.sorted();
        int32_t i;
        std::cin >> i;
        return Foo(*this).sorted();
    }
};

int main() {
    Foo f;
    f.sorted();
    return 0;
}
