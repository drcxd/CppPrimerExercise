#include <iostream>

int main() {
    const uint32_t BUF_SIZE = 8;
    char *buffer = new char[BUF_SIZE + 1];
    uint32_t i = 0;
    char c;
    while (i < BUF_SIZE && std::cin >> c) {
        buffer[i] = c;
        ++i;
        if (i >= BUF_SIZE) {
            std::cout << "string is too long\n";
            buffer[i] = '\0';
            std::cout << "limited string is " << buffer << std::endl;
            i = 0;
        } 
    }
    buffer[i] = '\0';
    std::cout << "string is " << buffer << std::endl;

    return 0;
}
