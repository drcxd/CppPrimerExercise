#include <iostream>

template<typename T, unsigned N>
const T *begin(const T (&arr)[N]) {
    return &arr[0];
}

template<typename T, unsigned N>
const T *end(const T (&arr)[N]) {
    return &arr[N - 1];
}

int main() {
    int arr[5] = {0, 1, 2, 3, 4};
    std::cout << *begin(arr) << std::endl;
    std::cout << *end(arr) << std::endl;
    
    return 0;
}
