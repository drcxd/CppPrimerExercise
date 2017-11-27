template <typename C>
void print(const C &container) {
    typename C::const_iterator it = container.cbegin();
    while (it != contianer.cend()) {
        std::cout << *it << std::endl;
        ++it;
    }
}
