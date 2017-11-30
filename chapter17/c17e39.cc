#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream file("test.txt", fstream::ate | fstream::in | fstream::out);
    if (!file.is_open()) {
        cout << "Can't open file 'test.txt'!\n";
        return 0;
    }
    auto origin_end = file.tellg();
    auto write_mark = file.tellp();
    file.seekg(0, fstream::beg);
    auto read_mark = file.tellg();
    int next_newline = 0;
    string line;
    while (read_mark != origin_end) {
        getline(file, line);
        next_newline += line.size() + 1;
        read_mark = file.tellg();
        file.seekp(write_mark);
        file << next_newline << " ";
        write_mark = file.tellp();
        file.seekg(read_mark);
    }
    file.seekp(0, fstream::end);
    file << endl;    
    return 0;
}
