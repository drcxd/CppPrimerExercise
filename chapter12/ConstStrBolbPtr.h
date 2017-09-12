#pragma once

#include "StrBlob.h"

#include <string>
#include <vector>
#include <memory>
class ConstStrBlobPtr {
public:
    ConstStrBlobPtr() : curr(0) { }
    ConstStrBlobPtr(const StrBlob &a, size_t sz = 0)
        : wptr(a.data)
        , curr(sz) { }
    const std::string &deref() const;
    StrBlobPtr &incr();    // prefix version
private:
    // check returns a shared_ptr to the vector if the check success
    std::shared_ptr<const std::vector<std::string>>
    check(std::size_t, const std::string &) const;
    // store a waek_ptr, which means the underlying vector might be destroyed
    std::weak_ptr<const std::vector<std::string>> wptr;
    std::size_t curr;     // current position within the array
};
