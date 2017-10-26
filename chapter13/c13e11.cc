HasPtr::~HasPtr() {
    delete ps;
    ps = nullptr;
}
