#pragma once
#include <memory>
#include <string>
#include <utility>
#include <initializer_list>

class StrVec {
public:
    StrVec()
        : elements(nullptr)
        , first_free(nullptr)
        , cap(nullptr) { }
    StrVec(const StrVec &);
    StrVec(StrVec &&);
    StrVec(const std::initializer_list<std::string> &il);
    StrVec &operator=(const StrVec &);
    StrVec &operator=(StrVec &&);
    ~StrVec();    
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }
    void push_back(const std::string &);
    void reserve(size_t n);
    void resize(size_t n);
private:
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<std::string *, std::string *>
    alloc_n_copy(const std::string *, const std::string *);
    void free();
    void reallocate(size_t n = 0);
    
    static std::allocator<std::string> alloc;
    std::string *elements;
    std::string *first_free;
    std::string *cap;
};
