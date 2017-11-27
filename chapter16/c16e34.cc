template <class T> int compare(const T &, const T &);
// (a)
compare("hi", "world");
// (b)
compare("bye", "dad");

/* (a) is illegal. Because the parameter is a reference, the
 * array-to-pointer conversion will not be performed. Type of "hi" is
 * const char[3] while type of "world" is const char[5], types are
 * different. (b) is legal, both arguments have type const char[3].
 */
