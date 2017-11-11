bool operator==(const StrVec &lhs, const StrVec &rhs) {
    if (lhs.size() != rhs.size()) {
        return false;
    }
    if (lhs.elements == rhs.elements) {
        return true;
    }
        
    for (uint i = 0; i < lhs.size(); ++i) {
        if (*(lhs.elements + i) != *(rhs.elements + i)) {
            return false;
        }
    }
    return true;    
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
    return lhs.wptr == rhs.wptr &&
        lhs.curr == rhs.curr;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}
