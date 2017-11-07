/* I write the test program instaed of using TextQuery and QueryResult
 * in the purpose of make things easy and clear.
 */

#include "StrVec.h"

#include <iostream>

int main() {
    StrVec v;
    v.push_back("Monday");
    v.push_back("Tuesday");
    v.push_back("Wednesday");
    std::cout << "size of v is " << v.size() << "\n3 is expected\n";
    std::cout << "capacity of v is " << v.capacity() << "\n4 is expected\n";
    for (auto it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << std::endl;
    }
    v.reserve(16);
    std::cout << "now capacity of is " << v.capacity() << "\n16 is expected\n";
    v.resize(4);
    std::cout << "now size of v is " << v.size() <<"\n4 is expected\n";

    StrVec v1 = v, v2;
    v2 = v1;
    for (auto it = v1.begin(); it != v1.end(); ++it) {
        std::cout << *it << std::endl;
    }
    for (auto it = v2.begin(); it != v2.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
