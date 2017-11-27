#include "DebugDelete.h"

template <typename T, typename D> class my_unique_ptr;
template <typename T, typename D>
void
swap(my_unique_ptr<T, D> &lhs, my_unique_ptr<T, D> &rhs);

template <typename T, typename D = DebugDelete>
class my_unique_ptr {
    friend void swap(my_unique_ptr &lhs, my_unique_ptr &rhs);
public:
    my_unique_ptr() : obj(nullptr), deleter(D()) { }
    my_unique_ptr(T t) : obj(&t), deleter(D()) { }
    explicit my_unique_ptr(T *t) : obj(t), deleter(D()) { }
    my_unique_ptr(const my_unique_ptr &u) = delete;
    my_unique_ptr &operator=(const my_unique_ptr &u) = delete;
    my_unique_ptr(my_unique_ptr &&u) noexcept : obj(u.obj), deleter(u.deleter) { u.obj = nullptr; }
    my_unique_ptr &operator=(my_unique_ptr &&u) const {
        if (u.obj != obj) {
            deleter(obj);
            obj = u.obj;
            u.obj = nullptr;
        }
        return *this;
        
    }
    T &operator*() const { return *obj; }
    T *operator->() const { return &this->operator*(); }
    operator bool() const { return obj ? true : false; }
    T *get() const { return obj; }
    void swap(my_unique_ptr &rhs) { ::swap(*this, rhs); }
    void reset() noexcept { deleter(obj); obj = nullptr; }
    void reset(T *) noexcept { deleter(obj); obj = p; }
    T* release() { auto p = obj; obj = nullptr; return p; }
    ~my_unique_ptr() { deleter(obj); }
    
private:
    T *obj;
    D deleter;
};

template <typename T, typename D>
void swap(my_unique_ptr<T, D> &lhs, my_unique_ptr<T, D> &rhs) {
    std::swap(lhs.obj, rhs.obj);
    std::swap(lhs.deleter, rhs.deleter);
}
