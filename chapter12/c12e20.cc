#include "StrBlob.h"
#include "StrBlobPtr.h"

#include <fstream>
#include <iostream>
#include <vector>
#include <memory>
#include <string>

using namespace std;

int main() {
    StrBlob sb;
    ifstream input("input.txt");
    string line;
    while (getline(input,line)) {
        sb.push_back(line);
    }

    StrBlobPtr sbp = sb.begin();
    size_t size = sb.size();
    uint32_t i = 0;
    while (i < size) {
        line = sbp.deref();
        cout << line << endl;
        sbp.incr();
        ++i;
    }
        
    return 0;
}
