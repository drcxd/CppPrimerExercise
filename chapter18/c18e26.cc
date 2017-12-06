/* The call to print is in error because the print defined in MI hide
 * all print in its base classes. Since the argument type is different
 * from the parameter type, the call is in error.
 */
struct MI: public Derived, public Base2 {
    void print(std::vector<double>);
    void print(int i) { Base1::print(i); }
    // ... same as before
};
