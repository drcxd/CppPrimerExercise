template <typename T> void g(T &&val);
int i = 0; const int ci = i;
// (a)
g(i); // i is lvalue, so T is deduced as int &. val has type int &.
// (b)
g(ci); // ci is lvalue, so T is deduced as const int &. val has type const int &.
// (c)
g(i * ci); // i * ci is rvalue, so T is deduced as int, val has type T &&.
