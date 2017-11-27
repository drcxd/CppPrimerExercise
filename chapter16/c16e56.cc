#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <typename T>
std::string debug_rep(const T &t) {
    std::ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
std::string debug_rep(T *p) {
    std::ostringstream ret;
    ret << "pointer: " << p;
    if (p) {
        ret << " " << debug_rep(*p);
    } else {
        ret << " null pointer";
    }
    return ret.str();
}

std::string debug_rep(const std::string &s) {
    return '"' + s + '"';
}

std::string debug_rep(char *p) {
    return debug_rep(std::string(p));
}

std::string debug_rep(const char *p) {
    return debug_rep(std::string(p));
}

template <typename T>
ostream &print(ostream &os, const T &t) {
    return os << t;
}

template <typename T, typename ... Args>
ostream &print(ostream &os, const T &t, const Args& ... rest) {
    os << t << ", ";
    return print(os, rest...);
}

template <typename ... Args>
void errorMsg(ostream &os, const Args&... args) {
    print(os, debug_rep(args)...);
}

int main() {
    int i = 0; double d = 31.4; string s = "fail"; float f = 0.01; char c = 'm';
    errorMsg(cout, i, d, s, f, c);
    cout << endl;
    return 0;
}
