#include <iostream>
#include <string>
#include <fstream>

class LengthTest {
public:
    LengthTest(int upper_bound, int lower_bound)
        : upper_bound_(upper_bound)
        , lower_bound_(lower_bound) {
        
    }

    bool operator()(std::string s) { return s.length() >= lower_bound_ && s.length() <= upper_bound_; }
private:
    int upper_bound_;
    int lower_bound_;
};

int main() {
    std::ifstream input("c14e10.txt");
    if (!input) {
        std::cerr << "Can't open file 'c14e10.txt'!\n";
        return 0;
    }
    int count = 0;
    std::string word;
    LengthTest lt(10, 1);
    while (input) {
        input  >> word;
        if (lt(word)) {
            ++count;
        }
    }
    std::cout << "Count of words whose length is between 1 and 10 inclusive is " << count << std::endl;
    return 0;
}
