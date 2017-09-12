#include <memory>
#include <string>
#include <iostream>

using namespace std;

int main() {
    const int32_t n = 10;
    allocator<string> string_allocator;
    auto const p = string_allocator.allocate(n);
    string *q = p;
    string s;
    while (cin >> s && q != p + n) {
        uninitialized_fill_n(q, 1, s);
        ++q;
    }
    size_t size = q - p;

    for (string *r = p; r != q; ++r) {
        cout << *r << std::endl;
    }
    
    for (string *d = p; d != q; ++d) {
        string_allocator.destroy(d);
    }
    string_allocator.deallocate(p, n);
    
    return 0;
}
