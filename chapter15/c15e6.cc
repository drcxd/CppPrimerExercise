#include "Quote.h"
#include "Bulk_quote.h"

double print_total(std::ostream &os, const Quote &item, size_t n);

int main() {
    Bulk_quote bq("10011", 15.6, 10, 0.6);
    Quote q("10012", 10);
    print_total(std::cout, bq, 15);
    print_total(std::cout, q, 20);
    return 0;
}
