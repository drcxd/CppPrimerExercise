Base::Base() : Class() { }
Base::Base(const Base &b) : Class(b) { }
Base::Base(int i) : Class() { }

D1::D1() : Base() { }
D1::D1(const D1 &d1) : Base(d1) { }
D1::D1(int i) : Base(i) { }

D2::D2() : Base() { }
D2::D2(const D2 &d2) : Base(d2) { }
D2::D2(int i) : Base(i) { }

MI::MI() : Base(), D1(), D2() { }
MI::MI(const MI &mi) : Base(mi), D1(mi), D2(mi) { }
MI::MI(int i) : Base(i), D1(i), D2(i) { }

Final::Final() : Base(), MI(), Class() { }
Final::Final(const Final &f) : Base(f), MI(f), Class(f) { }
Final::Final(int i) : Base(i), MI(i), Class(i) { }
