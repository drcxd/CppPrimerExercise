bool operator<(const StrVec &lhs, const StrVec &rhs) {
    if (lhs.elements && rhs.elements) {
        for (unsigned i = 0; i < lhs.size() && i < rhs.size(); ++i) {
            if (*(lhs.elements + i) < *(rhs.elements + i)) {
                return true;
            }
        }
        return lhs.size() < rhs.size();
    } else if (!lhs.elements && rhs.elements) {
        true;
    } else {
        false;
    }
}

bool operator<=(const StrVec &lhs, const StrVec &rhs) {
    return lhs < rhs || lhs == rhs;
}

bool operator>(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs <= rhs);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs < rhs);
}
