#include "Quote.h"
#include "Bulk_quote.h"

int main() {
    Bulk_quote bq1, bq2;
    Bulk_quote bq3(bq2);
    bq1 = bq2;
    
    return 0;
}
