#include <string>
#include <sstream>

using namespace std;

template <typename T> string debug_rep(const T &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T> string debug_rep(T *p) {
    ostringstream ret;
    ret << "pointer: " << p;
    if (p) {
        ret << " " << debug_rep(*p);
    } else {
        ret << " null pointer";
    }
    return ret.str();
}

template <>
string debug_rep(const char * const &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
} // T is const char *

template <>
string debug_rep(char * const &t) {
    ostringstream ret;
    ret << t;
    return ret.str();
} // T is char *
