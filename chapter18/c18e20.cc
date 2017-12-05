#include <iostream>

using std::endl;
using std::cout;

namespace primerLib {
void compute() { cout << "primerLib no argument version\n"; }
void compute(const void *) { cout << "primerLib const void * version\n"; }
}
// using primerLib::compute;
void compute(int) { cout << "global int version\n"; }
void compute(double, double = 3.4) { cout << "global double version\n"; }
void compute(char*, char* = 0) { cout << "global char * version\n"; }

void f() {
    compute(0);
}

int main() {
    using primerLib::compute;
    f();
    return 0;
}

// Both situation will call the int version. For int version is an
// exactly match.  To call const void *, double, char * version need
// conversion to that tpye. Place using delcaration in main() won't
// hide the global functions, for they have different parameter list.
