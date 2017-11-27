#pragma once

#include <iostream>
#include <string>

template <unsigned, unsigned> class Screen;

template <unsigned W, unsigned H>
std::ostream &operator<<(std::ostream &os, const Screen<W, H> &s) {
    os << s.width << " " << s.height;
    return os;
}

template <unsigned W, unsigned H>
std::istream &operator>>(std::istream &is, Screen<W, H> &s) {
    is >> s.content;
    return is;
}

template <unsigned W, unsigned H>
class Screen {
    friend std::ostream &operator<<<W, H>(std::ostream &os, const Screen &s);
    friend std::istream &operator>><W, H>(std::istream &is, Screen &s);
public:
    Screen() : width(W), height(H) { }
private:
    int width;
    int height;
    std::string content;
};

