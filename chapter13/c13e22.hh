#include <string>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s))
        , i(0) { }
    ~HasPtr() { delete ps; }
    HasPtr(const HasPtr &rhs)
        : ps(new std::string(*rhs.ps))
        , i(rhs.i) { }
    const HasPtr &operator=(const HasPtr &rhs) {
        auto temp = new std::string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }
};
