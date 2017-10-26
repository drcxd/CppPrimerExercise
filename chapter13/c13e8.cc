HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    i = rhs.i;
    delete ps;
    auto tmp = new std::string(*rhs.ps);
    ps = tmp;
    return *this;
}
