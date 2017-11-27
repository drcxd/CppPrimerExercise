#pragma once

#include "Blob.h"

#include <stdexcept>

template <typename T> class BlobPtr {
public:
    BlobPtr() : curr(0) { }
    BlobPtr(Blob<T> &a, size_t sz = 0) : wptr(a.data), curr(sz) { }
    T &operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    BlobPtr &operator++();
    BlobPtr &operator--();
private:
    std::shared_ptr<std::vector<T>>
    check(std::size_t, const std::string &) const;
    std::weak_ptr<std::vector<T>> wptr;
    std::size_t curr;
};

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator++() {
    ++*this;
    return *this;
}

template <typename T>
BlobPtr<T> &BlobPtr<T>::operator--() {
    --*this;
    return *this;
}

template <typename T>
std::shared_ptr<std::vector<T>>
BlobPtr<T>::check(std::size_t s, const std::string &msg) const {
    auto p = wptr.lock();
    if (!p) {
        throw std::runtime_error("unbound BlobPtr");
    }
    if (s >= p->size()) {
        throw std::out_of_range(msg);
    }
    return p;
}

