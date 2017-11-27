template <typename T> T calc(T, int);
template <typename T> T fcn(T, T);
double d; float f; char c;
// (a)
calc(c, 'c');
// (b)
calc(d, f);
// (c)
fcn(c, 'c');
// (d)
fcn(d, f);

/* 

(a) is legal. T is char. 'c' is converted to int.

(b) is legal. T * is double, f is converted to int.

(c) legal, T is char.

(d) is illegal, for both function parameter is of template parameter
type, the arithematic conversion will not be performed, so no
matching function can be found.

 */
