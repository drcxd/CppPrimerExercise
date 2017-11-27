#include <vector>

struct NoDefault {
    NoDefault() = delete;
};

template class std::vector<NoDefault>;
int main() {    
    return 0;
}

/* Not. An instantiation definition instantiates all members of the
 * template. std::vector has at least a member have to call the
 * default constructor of the typename parameter. Since NoDefault has
 * no default constructor, the member cannot be instantiated. As a
 * result, the program can't be compiled.
 */
