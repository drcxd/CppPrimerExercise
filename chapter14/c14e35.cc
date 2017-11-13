#include <iostream>
#include <string>

class StringReader {
public:
    StringReader(std::istream &is = std::cin)
        : m_is(is) { }
    std::string operator()() {
        std::string temp;
        m_is >> temp;
        if (!m_is) {
            temp = "";
        }
        return temp;
    }

private:
    std::istream &m_is;
};
