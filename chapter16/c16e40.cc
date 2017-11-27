template <typename It>
auto fc3(It beg, It end) -> decltype(*beg + 0) {
    return *beg;
}

/*
  It is legal. However, the *It type must support operator+ with a
  second arguments whose type can be converted from 0. The return type
  is the type of *beg without reference, for the operator+ usually
  yields a lvalue.
*/
