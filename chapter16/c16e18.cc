/* (a) illegal */
template <typename T, typename U, typename V> void f1(T, U, V);

/* (b) illegal */
template <typename T> T f2(int &);

/* (c) illegal */
template <typename T> inline T foo(T, unsigned int *);

/* (d) illegal */
template <typename T> void f4(T, T);

/* (e) legal */
