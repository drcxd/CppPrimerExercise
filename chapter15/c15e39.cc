#include "TextQuery.h"
#include "QueryResult.h"
#include "Query_base.h"
#include "Query.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"

#include <fstream>

int main() {
    std::ifstream input("input.txt");
    TextQuery tq(input);
    // Query q = Query("fiery") & Query("bird") | Query("wind");
    // Query q = Query("fiery");
    Query q = Query("bird,");
    print(std::cout, q.eval(tq));
    return 0;
};
