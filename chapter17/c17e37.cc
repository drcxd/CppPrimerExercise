/* If there is a line whose length is larger than the size parameter
 * of getline function, the istream will set the fail bit. If there is
 * an empty line, the new line character will still be read but not
 * stored.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    std::ifstream input("test.txt");
    char buffer[64];
    int size = 0;
    while (input.getline(buffer, 64, '\n')) {
        size = input.gcount();        
        cout.write(buffer, size);
        cout << endl;
    }
    
    return 0;
}
