#include <memory>

int main() {
    std::unique_ptr<int> up(new int(4));
    std::unique_ptr<int> up2;
    up2 = up;
    
    return 0;
}
