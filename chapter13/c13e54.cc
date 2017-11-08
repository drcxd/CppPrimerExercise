/* The compiler will not know which version of operator= to call.
*/
#include <string>
#include <iostream>

class HasPtr {
public:
    HasPtr(const std::string &s = std::string())
        : ps(new std::string(s))
        , i(0) { }
    HasPtr(const HasPtr &p)
        : ps(new std::string(*p.ps))
        , i(p.i) { }
    HasPtr &operator=(const HasPtr &rhs) {
        std::cout << "copy assignment called\n";
        auto temp = new std::string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }
    HasPtr &operator=(HasPtr &&rhs) {
        std::cout << "move assignment called\n";
        if (this != &rhs) {
            ps = rhs.ps;
            i = rhs.i;
            rhs.ps = nullptr;
        }
        return *this;
    }
    HasPtr &operator=(HasPtr rhs) {
        std::cout << "copy-and-swap version called\n";
        swap(*this, rhs);
        return *this;
    }
    ~HasPtr() { delete ps; }
    void swap(HasPtr &lhs, HasPtr &rhs) {
        using std::swap;
        swap(lhs.ps, rhs.ps);
        swap(lhs.i, rhs.i);
    }
private:
    std::string *ps;
    int i;
};

int main() {
    HasPtr hp1, hp2;
    hp2 = hp1;
    hp2 = std::move(hp1);
    
    return 0;
}
