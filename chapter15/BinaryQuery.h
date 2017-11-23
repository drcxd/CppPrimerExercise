#pragma once
#ifndef _BINARY_QUERY_H_
#define _BINARY_QUERY_H_

class BinaryQuery : public Query_base {
protected:
    BinaryQuery(const Query &l, const Query &r, std::string s)
        : lhs(l)
        , rhs(r)
        , opSym(s) { /* std::cout << "BinaryQuery constructor called\n";*/ }
    std::string rep() const override{
        // std::cout << "BinaryQuery rep called\n";
        return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
    }
    Query lhs, rhs;
    std::string opSym;
};

#endif
