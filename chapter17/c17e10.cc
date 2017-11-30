#include <bitset>

int main() {
    int arr[] = {1, 2, 3, 4, 8, 13, 21};
    std::bitset<32> bv;
    for (auto i : arr) {
        bv.set(i, true);
    }
    return 0;
}
