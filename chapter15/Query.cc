#include "Query.h"
#include "WordQuery.h"

std::ostream &operator<<(std::ostream &os, const Query &query) {
    return os << query.rep();
}

Query::Query(const std::string &s)
    : q(new WordQuery(s)) {
    // std::cout << "Query constructor called\n";
}
