#pragma once

#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <set>

// class TextQuery;
class QueryResult {
    friend std::ostream &print(std::ostream&, const QueryResult &);
public:
    using line_no = std::vector<std::string>::size_type;
    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p,
        std::shared_ptr<std::vector<std::string>> f)
        : sought(s)
        , lines(p)
        , file(f) { }
    std::set<line_no>::const_iterator begin() const { return lines->cbegin(); }
    std::set<line_no>::const_iterator end() const { return lines->cend(); }
    std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
