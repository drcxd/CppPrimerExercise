#include "TextQuery.h"
#include "QueryResult.h"
#include "Query.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "BinaryQuery.h"
#include "OrQuery.h"
#include "AndQuery.h"

int main() {
    Query q = Query("fiery") & Query("bird") | Query("wind");
    std::cout << q;
    return 0;
}
