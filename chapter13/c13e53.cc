/* Maybe it's because the copy-and-swap version makes a copy of the
 * rhs instead of use the reference directly. And it calls the
 * standard swap function.
 */

HasPtr &HasPtr::operator=(const HasPtr &rhs) {
    auto temp = new std::string(*rhs.ps);
    delete ps;
    ps = temp;
    i = rhs.i;
    return *this;
}

HasPtr &HasPtr::operator=(HasPtr &&rhs) {
    if (this != &rhs) {
        ps = rhs.ps;
        i = rhs.i;
        rhs.ps = nullptr;
    }
    return *this;
}
