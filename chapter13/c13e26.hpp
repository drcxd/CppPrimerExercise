#pragma once

/* StrBlob doesn't need a special destructor for the vecotr of string
 * is managed by the std::shared_ptr, which will decide whether the
 * underlying object should be destroyed.
 */

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
class StrBlobPtr;
class StrBlob {
    friend class StrBlobPtr;
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    StrBlob(const StrBlob &rhs);
    const StrBlob &operator=(const StrBlob &rhs);
    ~StrBlob();
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const std::string &t) { data->push_back(t); }
    void pop_back();
    std::string& front();
    const std::string& front() const;
    std::string& back();
    const std::string& back() const;
    StrBlobPtr begin(); 
    StrBlobPtr end(); 
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};

StrBlob::StrBlob(const StrBlob &rhs)
    : data(std::make_shared(std::vector<std::string>(*rhs.data))){ }

const StrBlob &StrBlob::operator=(const StrBlob &rhs) {
    auto temp = *rhs.data;
    data.release();
    data = &temp;
    return *this;
}
