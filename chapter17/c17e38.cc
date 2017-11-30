#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    std::ifstream input("test.txt");
    char buffer[64];
    int size = 0;
    char *start = nullptr;
    char *end = nullptr;
    while (input.getline(buffer, 64, '\n')) {
        size = input.gcount();
        start = end = buffer;
        while (*end) {
            ++end;
            if (*end == ' ') {
                cout.write(start, end - start);
                cout << endl;
                start = end = end + 1;
            }
        }
        cout.write(start, end - start);
        cout << endl;
    }
    
    return 0;
}
