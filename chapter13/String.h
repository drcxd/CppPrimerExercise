#include <memory>
#include <utility>

/* A String is like a vector of char. So this class is analogue to
 * StrVec. I just give the header file and am too lazy to write the
 * implementation.
 */

class String {
public:
    String()
        : elements(nullptr)
        , first_free(nullptr)
        , cap(nullptr) { };
    String(const char *); // call append until we meet the '\0'
    String(const String &);
    String &operator=(const String &);
    ~String();
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    char *begin() const { return elements; }
    char *end() const { return first_free; }
    void append(const char); // analogue to push_back
private:
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    std::pair<char *, char *>
    alloc_n_copy(const char *, const char *);
    void free();
    void reallocate();
    
    char *elements;
    char *first_free;
    char *cap;
    static std::allocator<char> alloc;
};
