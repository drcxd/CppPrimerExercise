#include <vector>

template <typename T> void g(T &&val) { std::vector<T> v; }

int main() {
    g(42);
    int i = 0;
    // g(i);
    return 0;
}

// On g(42), T is deduced as int, so vector<T> is legal.  On g(i), T
// is deduced as int &, val is int &, so vector<T> is illegal.
