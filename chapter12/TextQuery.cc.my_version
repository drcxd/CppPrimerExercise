#include "TextQuery.h"
#include "QueryResult.h"

#include <sstream>
#include <iostream>

using namespace std;

TextQuery::TextQuery(ifstream &infile)
    : m_shared_text(new std::vector<std::string>)
    , m_shared_linenumber_map(new std::map<std::string, std::set<int>>)
    , m_shared_count_map(new std::map<std::string, int>)
{
    
    string line;
    while (getline(infile, line)) {
        m_shared_text->push_back(line);
    }
    
}

QueryResult TextQuery::query(const string &query_word) {
    cout << "query start...\n";
    auto beg = m_shared_text->begin();
    auto end = m_shared_text->end();
    uint32_t linenumber = 0;
    for ( ; beg != end; ++beg) {
        istringstream line(*beg);
        string word;
        while (line >> word) {
            if (word == query_word) {
                ++(*m_shared_count_map)[word];
                (*m_shared_linenumber_map)[word].insert(linenumber);
            }
        }
        ++linenumber;
    }
    cout << "query end...\n";
    return QueryResult(*this, query_word);
}
