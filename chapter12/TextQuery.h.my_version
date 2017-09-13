#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

class QueryResult;

class TextQuery {
    friend class QueryResult;
public:
    // TextQuery() { }
    TextQuery(std::ifstream &infile);

    QueryResult query(const std::string &word);

private:
    // std::vector<std::string> m_text;
    // std::map<std::string, std::set<int>> m_word_linenumber_map;
    // std::map<std::string, int> m_word_count_map;
    std::shared_ptr< std::vector<std::string>> m_shared_text;
    std::shared_ptr< std::map<std::string, std::set<int>>> m_shared_linenumber_map;
    std::shared_ptr< std::map<std::string, int>> m_shared_count_map;
};
