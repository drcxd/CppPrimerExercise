ostream &operator<<(ostream &os, const String &s) {
    if (s.elements) {
        for (auto i = s.elements; i != s.first_free; ++i) {
            os << *i;
        }
    }
}
