/* Method 1: Use a class object to manage the resources. Method 2:
 * throw the pointer p and free the resources in the catch block.
 */

class IntArray {
public:
    IntArray() : p(nullptr) { }
    IntArray(std::size_t size) : p(new int[size]) { }
    ~IntArray() { delete p; }
private:
    int *p;
};

void exercise(int *b, int *e) {
    vector<int> v(b, e);
    // Method 1
    // IntArray arr(v.size());
    // Method 2
    int *p = new int[v.size()];
    ifstream in("ints");
    throw p;
    // ...
}

// somewhere
// catch (int * p) {
//     // ...
//     delete [] p;
// }
