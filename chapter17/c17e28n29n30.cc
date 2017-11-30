#include <iostream>
#include <random>
#include <ctime>

unsigned my_rand(unsigned min = 0, unsigned max = RAND_MAX, unsigned long long seed = 0) {
    static std::default_random_engine e(seed);
    static std::uniform_int_distribution<unsigned> u(min, max);
    return u(e);
}

int main() {
    for (unsigned i = 0; i < 10; ++i) {
        std::cout << my_rand() << std::endl;
    }
    return 0;
}
