#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <memory>

class QueryResult;

class TextQuery {
    // friend class QueryResult;
public:
    // TextQuery() { }
    using line_no = std::vector<std::string>::size_type;
    TextQuery(std::ifstream &infile);
    QueryResult query(const std::string &word) const;
private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
