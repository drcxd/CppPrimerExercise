#include "String.h"

#include <iostream>

String::String(const char *) {
    
}

String::String(const String &s) {
    std::cout << "copy constructor called\n";
}

String::String(String &&s) noexcept {
    std::cout << "move constructor called\n";
}

String &String::operator=(const String &s) {
    std::cout << "copy-assignment operator called\n";
    return *this;
}

String &String::operator=(String &&s) noexcept {
    std::cout << "move-assignment operator called\n";
    return *this;
}

String::~String() {
    
}
