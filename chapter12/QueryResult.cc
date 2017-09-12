#include "QueryResult.h"
#include "TextQuery.h"

#include <iostream>

using namespace std;

QueryResult::QueryResult(const TextQuery &tq, const string &query_word)
    : m_shared_text(tq.m_shared_text)
    , m_shared_linenumber_map(tq.m_shared_linenumber_map)
    , m_shared_count_map(tq.m_shared_count_map)
    , m_query_word(query_word) { }

ostream &QueryResult::print(ostream &os, const QueryResult &qr) {
    if (qr.m_shared_count_map->find(qr.m_query_word) != qr.m_shared_count_map->end()) {
        os << "The word [" << qr.m_query_word << "] occurs " <<
            qr.m_shared_count_map->find(qr.m_query_word)->second << " times\n";
        auto beg = qr.m_shared_linenumber_map->find(qr.m_query_word)->second.begin();
        auto end = qr.m_shared_linenumber_map->find(qr.m_query_word)->second.end();
        cout << "size of set is " << qr.m_shared_linenumber_map->find(qr.m_query_word)->second.size() << endl;
        for ( ; beg != end; ++beg) {
            os << "\t" << "(line " << *beg  << ") " << qr.m_shared_text->at(*beg) << endl;
        }
    } else {
        os << "no such word [" << qr.m_query_word << "]\n";
    }
    return os;
}
