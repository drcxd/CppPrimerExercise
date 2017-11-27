template <typename T> f1(T, T);
template <typename T1, typename T2> f2(T1, T2);
int i = 0, j = 42, *p1 = &i, *p2 = &j;
const int *cp1 = &i, *cp2 = &j;
// (a)
f1(p1, p2);
// (b)
f2(p1, p2);
// (c)
f1(cp1, cp2);
// (d)
f2(cp1, cp2);
// (e)
f1(p1, cp1);
// (f)
f2(p1, cp1);

/*
  
  (a) p1, p2 have the same type int *, the call will succeed.

  (b) since T1 and T2 is of different types, the call will succeed.

  (c) cp1 and cp2 have the same type const int *, the caoo will succeed.

  (d) same as (b)

  (e) p1 has type int *, cp1 has type const int *. T is const int
  *. const conversion is peformed on p1. the call will succeed.

  (f) since T1 and T2 is of different types, the call will succeed. no
  conversion will be performed.

 */
