#include <iostream>
#include <string>

class Screen {
public:
    typedef std::string::size_type pos;
    pos Screen::*get() { return &Screen::cursor; }
    // ...
private:
    pos cursor;
    // ...
};

int main() {
    Screen s;
    Screen::pos Screen::*pcursor;
    pcursor = s.get();
    std::cout << s.*pcursor << std::endl;
    return 0;
}
