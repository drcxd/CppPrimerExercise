#include <limits>
#include <iostream>

template <typename T> struct promote;

template <> struct promote<short> {
    using type = int;
};

template <> struct promote<unsigned short> {
    using type = unsigned int;
};

template <> struct promote<int> {
    using type = long long int;
};

template <> struct promote<unsigned int> {
    using type = unsigned long int;
};

template <> struct promote<long int> {
    using type = long long int;
};

template <> struct promote<unsigned long int> {
    using type = unsigned long int;
};

template <> struct promote<long long int> {
    using type = unsigned long long int;
};

template <> struct promote<unsigned long long int> {
    using type = unsigned long long int;
};

template <> struct promote<float> {
    using type = double;
};

template <> struct promote<double> {
    using type = long double;
};

template <> struct promote<long double> {
    using type = long double;
};

template <typename T> using promote_t = typename promote<T>::type;

template <typename T> auto sum(T lhs, T rhs) -> promote_t<T> {
    return static_cast<promote_t<T>>(lhs) + rhs;
}

int main() {
    std::cout << sum(std::numeric_limits<short>::max(),
        std::numeric_limits<short>::max()) << std::endl;
    // std::cout << sum(std::numeric_limits<double>::max(),
    //     std::numeric_limits<double>::max()) << std::endl;
    std::cout << sum(std::numeric_limits<unsigned long long int>::max(),
        std::numeric_limits<unsigned long long int>::max()) << std::endl;    
    return 0;
}
