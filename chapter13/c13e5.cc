HasPtr::HasPtr(const HasPtr &rhs)
    : i(rhs.i) {
    ps = new std::string(*rhs.ps);
}
