#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>

class TextQuery;
class QueryResult {
public:
    QueryResult(const TextQuery &tq, const std::string &s);
    static std::ostream &print(std::ostream &os, const QueryResult &qr);

private:
    std::shared_ptr<const std::vector<std::string>> m_shared_text;
    std::shared_ptr<const std::map<std::string, std::set<int>>> m_shared_linenumber_map;
    std::shared_ptr<const std::map<std::string, int>> m_shared_count_map;
    std::string m_query_word;
};
