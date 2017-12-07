#include <cstdlib>
#include <exception>

void *operator new(std::size_t size) {
    if (void *mem = std::malloc(size)) {
        return mem;
    } else {
        throw std::bad_alloc();
    }
}

void operator delete(void *mem) noexcept {
    free(mem);
}
