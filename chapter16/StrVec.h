#pragma once
#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

template <typename T>
class Vec {
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) { }
    Vec(const Vec &);
    Vec(Vec &&);
    Vec(const std::initializer_list<T> &il);
    Vec &operator=(const Vec &);
    Vec &operator=(Vec &&);
    ~Vec();
    size_t size() const { return first_free -elements; }
    size_t capacity() const { return cap - elements; }
    T *begin() const { return elements; }
    T *end() const { return first_free; }
    void push_back(const T &);
    void reserve(size_t n);
private:
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    void free();
    void reallocate(size_t n = 0);
    std::pair<T *, T *> alloc_n_copy(const T *b, const T *e);

    static std::allocator<T> alloc;
    T *elements;
    T *first_free;
    T *cap;
};

template <typename T>
std::allocator<T> Vec<T>::alloc;

template <typename T>
Vec<T>::Vec(const Vec &v) {
    auto newdata = alloc_n_copy(v.begin(), v.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>::Vec(Vec &&v) noexcept
    : elements(v.elements)
    , first_free(v.first_free)
    , cap(v.cap) {
    v.elements = v.first_free = v.cap = nullptr;
}

template <typename T>
Vec<T>::Vec(const std::initializer_list<T> &il) {
    auto newdata = alloc_n_copy(il.begin(), il.end());
    elemens = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &rhs) {
    auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = newdata.first;
    first_free = cap - newdata.second;
    return *this;
}

template <typename T>
Vec<T> &Vec<T>::operator=(const Vec &&rhs) {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
}

template <typename T>
Vec<T>::~Vec<T> {
    free();
}

template <typename T>
void Vec<T>::push_back(const T &t) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
std::pair<T *, T *>
Vec<T>::alloc_n_copy(const T *b, const T *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free() {
    if (elements) {
        for_each(elements, first_free,
            [] (T *p) -> void { alloc.destroy(p); });
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
void Vec<T>::reallocate(size_t n) {
    auto newcapacity = n == 0 ? size() ? size() : 1 : n;
    auto first = alloc.allocate(newcapacity);
    auto list = uninitialized_copy(make_move_iterator(begin()), make_move_iterator(end()), first);
    free();
    elements = first;
    first_free = last;
    cap = elements + newcapacity;
}

template <typename T>
void Vec<T>::reserve(size_t n) {
    while (n < capacity()) {
        reallocate();
    }
}

template <typename T>
void Vec<T>::resize(size_t n) {
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
