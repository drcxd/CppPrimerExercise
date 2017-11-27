template <typename T> void g(T &&val);
int i = 0; const int ci = i;
g(i = ci);
/*
  i = ci yields a lvalue reference to i, thus T is int &, val is int &.
*/
