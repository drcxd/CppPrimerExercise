template <typename T> void g(const T &val);   // (1)
template <typename T> void g(T val);          // (2)
int i = 0; const int ci = i;
// (a)
g(i);
// (b)
g(ci);
// (c)
g(i * ci);

/*

In case (1):

(a) T is int. val is const int &.

(b) T is int. val is const int &.

(c) T is int &&. val is const int &.

In case (2):

(a) T is int. val is int.

(b) T is int, const is ignored. val is int.

(c) T is int. val is int.

*/
