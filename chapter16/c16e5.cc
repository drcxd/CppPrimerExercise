#include <iostream>
#include <array>

// built-in array version
// template <unsigned N, typename T>
// void print(const T (&arr)[N]) {
//     for (auto &it : arr) {
//         std::cout << it << std::endl;
//     }
// }

// stl array version
template <unsigned long N, typename T>
void print(const std::array<T, N> &arr) {
    for (auto &it : arr) {
        std::cout << it << std::endl;
    }
}

int main() {
    // std::string arr[5] = {"one", "two", "three", "four", "five"};
    std::array<std::string, 5> arr = {"one", "two", "three", "four", "five"};
    print(arr);
    return 0;
}
