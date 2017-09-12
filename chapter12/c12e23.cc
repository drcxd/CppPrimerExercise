#include <string.h>
#include <iostream>
#include <string>

int main() {
    // version 1
    // const char *s1 = "hello";
    // const char *s2 = "world";
    // int32_t l1 = strlen(s1);
    // int32_t l2 = strlen(s2);
    // char *concatenated_string = new char[l1 + l2 + 1];
    // strcpy(concatenated_string, s1);
    // strcpy(concatenated_string + l1, s2);
    // concatenated_string[l1 + l2] = '\0';

    // std::cout << concatenated_string << std::endl;

    // version 2
    std::string s1 = "hello";
    std::string s2 = "world";
    std::size_t l1 = s1.size();
    std::size_t l2 = s2.size();
    char *concatenated_string = new char[l1 + l2 + 1];
    std::size_t i = 0;
    for ( ; i < l1; ++i) {
        concatenated_string[i] = s1[i];
    }
    for (size_t j = 0; j < l2; ++j) {
        concatenated_string[i] = s2[j];
        ++i;
    }
    concatenated_string[i] = '\0';
    std::cout << concatenated_string << std::endl;
    
    return 0;
}
