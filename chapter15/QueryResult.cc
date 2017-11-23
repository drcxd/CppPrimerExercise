#include "QueryResult.h"
#include "TextQuery.h"

#include <iostream>

using namespace std;

// QueryResult::QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
//     std::shared_ptr<std::vector<std::string>> f)
//     : m_shared_text(tq.m_shared_text)
//     , m_shared_linenumber_map(tq.m_shared_linenumber_map)
//     , m_shared_count_map(tq.m_shared_count_map)
//     , m_query_word(query_word) { }

ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << (qr.lines->size() > 1 ? "times" : "time") << endl;
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") "
           << *(qr.file->begin() + num) << endl;
    }
    return os;
}
