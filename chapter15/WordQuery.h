#pragma once
#ifndef _WORD_QUERY_H_
#define _WORD_QUERY_H_

#include "Query_base.h"
#include "QueryResult.h"

class WordQuery : public Query_base {
    friend class Query;
    WordQuery(const std::string &s) : query_word(s) { /*std::cout << "WordQuery constructor called\n";*/ }
    QueryResult eval(const TextQuery &t) const { return t.query(query_word); }
    std::string rep() const { /*std::cout << "WordQuery rep called\n";*/ return query_word; }
    std::string query_word;
};

#endif
