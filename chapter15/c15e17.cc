#include "Disc_quote.h"

int main() {
    Disc_quote dq;

    return 0;
}

/* ERROR MESSAGE BY CLANG V4.0.14
c15e17.cc:4:16: error: variable type 'Disc_quote' is an abstract class
    Disc_quote dq;
               ^
./Disc_quote.h:14:12: note: unimplemented pure virtual method 'net_price' in 'Disc_quote'
    double net_price(std::size_t) const = 0;
           ^
1 error generated.
 */
