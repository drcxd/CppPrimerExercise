class StrBlobPtr;

class PP {
public:
    StrBlobPtr &operator*();
    StrBlobPtr *operator->();
private:
    StrBlobPtr *pointer;
};

StrBlobPtr &PP::operator*() {
    return *(this->pointer);
}

std::string *PP::operator->() {
    return &this->operator*();
}
