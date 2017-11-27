#include <iostream>

using namespace std;

template <typename T>
ostream &print(ostream &os, const T &t) {
    return os << t;
}

template <typename T, typename ... Args>
ostream &print(ostream &os, const T &t, const Args& ... rest) {
    os << t << ", ";
    return print(os, rest...);
}

int main() {
    int i = 0; double d = 3.14; string s = "how now brown cow";
    char c = 'm'; float f = 0.01f;
    print(cout, c); cout << endl;
    print(cout, c, f); cout << endl;
    print(cout, i, d, s, c, f);
    cout << endl;
    return 0;
}
