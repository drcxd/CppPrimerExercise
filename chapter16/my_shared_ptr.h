#include "DebugDelete.h"

template <typename T> class my_shared_ptr;
template <typename T>
void swap(my_shared_ptr<T> lhs, my_shared_ptr<T> rhs);

template <typename T>
class my_shared_ptr {
    friend void swap(my_shared_ptr &lhs, my_shared_ptr &rhs);
public:
    my_shared_ptr() : obj(nullptr), count(nullptr), deleter(DebugDelete()) { }
    my_shared_ptr(T t) : obj(&t), count(new int(1)), deleter(DebugDelete()) { }
    my_shared_ptr(T *t) : obj(t), count(new int(1)), deleter(DebugDelete()) { }
    my_shared_ptr(my_shared_ptr &&p) noexcept
        : obj(p.obj)
        , count(p.count)
        , deleter(std::move(p.deleter)) {
        p.obj = nullptr;
        p.count = nullptr;
    }
    my_shared_ptr(const my_shared_ptr &p)
        : obj(p.obj)
        , count(p.count)
        , deleter(p.deleter) { ++*count; }
    my_shared_ptr &operator=(const my_shared_ptr &p) {
        auto temp = p;
        dec_n_delete();
        obj = p.obj;
        count = p.count;
        deleter = p.deleter;
        ++*count;
    }
    my_shared_ptr &operator=(my_shared_ptr &&p) noexcept {
        if (p.obj != obj) {
            dec_n_delete();
            obj = p.obj;
            count = p.count;
            deleter = p.deleter;
            p.obj = nullptr;
            p.count = nullptr;            
        }
        return *this;
        
    }
    ~my_shared_ptr() {
        dec_n_delete();
    }
    operator bool() const { return ptr ? true : false; }
    T &operator*() const { return *obj; }
    T *operator->() const { return &this->operator*(); }
    T *get() const noexcept { return obj; }
    int use_count const  { if (obj) return *count; else return 0; }
    bool unique() const { if (obj) return  *count == 1; else return false; }
    T *release { auto p = obj; p = nullptr; --*count; count = nullptr; return p; }
    void reset(T *t) {
        if (obj != t) {
            dec_n_delete();
            obj = t;
            count = new int(1);
        }
    }
    void reset(T *t, std::function<void (T *)> del) {
        reset(t);
        deleter = del;
    }
    void swap(my_shared_ptr<T> &rhs) {
        ::swap(*this, rhs);
    }
private:
    void dec_n_delete() {
        if (!obj) {
            --*count;
            if (*count == 0) {
                delete obj;
                delete count;
                obj = nullptr;
                count = nullptr;
            }
        }
    }
    
    T *obj;
    int *count;
    std::function<void (T*)> deleter;
};

template <typename T>
void swap(my_shared_ptr<T> &lhs, my_shared_ptr<T> &rhs) {
    std::swap(lhs.obj, rhs.obj);
    std::swap(lhs.count, rhs.count);
    std::swap(lhs.deleter, rhs.deleter);
}
