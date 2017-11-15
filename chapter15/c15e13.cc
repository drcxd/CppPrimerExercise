/* The print function in class derived intends to call the print
 * function defined by its base class. But with out the scope
 * operator, it actually calls itself which results in an infinite
 * recursion.
 */

void print(ostream &os) {
    base::print(os);
    os << " " << i;
}
