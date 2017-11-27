template <typename T, typename ... Args>
shared_ptr make_shared<T>(Args&&... args) {
    return shared_ptr<T>(new T(std::forward<Args>(args)...));
}
