#include <string>
#include <iostream>

template <typename T, typename ... Args>
void foo(const T &t, const Args& ... rest) {
    std::cout << sizeof...(Args) << " " << sizeof...(rest) << std::endl;
}

int main() {
    int i = 0; double d = 3.14; std::string s ="how now brown cow";
    foo(i, s, 42, d); // sizeof...(Args) is 3, sizeof...(rest) is 3    
    foo(s, 42, "hi"); // sizeof...(Args) is 2, sizeof...(rest) is 2
    foo(d, s);        // sizeof...(Args) is 1, sizeof...(rest) is 1
    foo("hi");        // sizeof...(Args) is 0, sizeof...(rest) is 0
    return 0;    
}


