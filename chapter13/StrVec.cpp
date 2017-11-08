#include "StrVec.h"

std::allocator<std::string> StrVec::alloc;

StrVec::StrVec(const StrVec &sv) {    
    auto newdata = alloc_n_copy(sv.begin(), sv.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec::StrVec(StrVec &&sv) noexcept
    : elements(sv.elements)
    , first_free(sv.first_free)
    , cap(sv.cap) {
    sv.elements = sv.first_free = sv.cap = nullptr;
}

StrVec::StrVec(const std::initializer_list<std::string> &il) {
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec &StrVec::operator=(const StrVec &rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap = newdata.second;
    return *this;
}

StrVec &StrVec::operaotr=(const StrVec &&rhs) {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

StrVec::~StrVec() {
    free();
}

void StrVec::push_back(const std::string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

std::pair<std::string *, std::string *>
StrVec::alloc_n_copy(const std::string *b, const std::string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        // for (auto p = first_free; p != elements; ) {
        //     alloc.destroy(--p);
        // }
        for_each(elements, first_free,
            [] (std::string *p) -> void { alloc.destroy(p); });
        alloc.deallocate(elements, cap - elements);
    }
}

// void StrVec::reallocate(size_t n) {
//     auto newcapacity = n == 0 ? size() ? 2 * size() : 1 : n;
//     auto newdata = alloc.allocate(newcapacity);
//     auto dest = newdata;
//     auto elem = elements;
//     for (size_t i = 0; i != size(); ++i) {
//         alloc.construct(dest++, std::move(*elem++));
//     }
//     free();
//     elements = newdata;
//     first_free = dest;
//     cap = elements + newcapacity;
// }

// another version
void StrVec::reallocate(size_t n) {
    auto newcapacity = n == 0 ? size() ? 2 * size() : 1 : n;
    auto first = alloc.allocate(newcapacity);
    auto last = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

void StrVec::reserve(size_t n) {
    while (n < capacity()) {
        reallocate();
    }
}

void StrVec::resize(size_t n) {
    if (n < size()) {
        auto p = first_free - 1;
        for ( ; p != elements + n - 1; ) {
            alloc.destroy(--p);
        }
        ++p;
        alloc.deallocate(p, cap - p);
        first_free = cap = p;
    } else if (n > size()) {
        while (n / 2 > size()) {
            reallocate();
        }
        while (size() < n) {
            push_back("");
        }
    }
}

// void StrVec::chk_n_alloc()
