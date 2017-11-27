#include <iostream>

template <unsigned N, typename T>
constexpr int size(const T (&arr)[N]) {
    return N;
}

int main() {
    int arr[5] = {0, 1, 2, 3, 4};
    std::cout << size(arr) << std::endl;
    return 0;
}
