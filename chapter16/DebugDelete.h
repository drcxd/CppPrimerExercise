#include <iostream>

class DebugDelete {
public:
    template <typename T> void operator(T *p) {
        std::cout << "Debug Delete" << std::endl;
        delete p;
    }
};
