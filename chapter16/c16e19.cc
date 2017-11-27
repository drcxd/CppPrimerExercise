#include <iostream>

template <typename C>
void print(const C &container) {
    auto beg = container.begin();
    for (typename C::size_type i = 0; i < container.size(); ++i) {
        std::cout << *(beg + i) << std::endl;
    }
}
