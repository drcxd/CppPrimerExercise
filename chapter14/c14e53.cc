/* Not legal. If use the member operator+, we need to first convert
 * 3.14 to int then to SmallInt. If use built-in operator+, we need to
 * first convert s1 to int then to double. It's ambiguous.
 */

SmallInt s1;
SmallInt s2 = 3.14;
double d = s1 + s2;
