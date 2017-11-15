#pragma once
#ifndef _QUOTE_H_
#define _QUOTE_H_

#include <string>
#include <iostream>

class Quote {
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price)
        : bookNo(book)
        , price(sales_price) { }
    Quote(const Quote &q) : bookNo(q.bookNo) , price(q.price) { std::cout << "Quote copy constructor is called\n"; }
    Quote &operator=(const Quote &rhs) {
        bookNo = rhs.bookNo;
        price = rhs.price;
        std::cout << "Quote copy-assignment operator is called\n";
        return *this;
    }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const {
        return n * price;
    }
    virtual ~Quote() {
        std::cout << "Quote destructor is called\n";
    }
    virtual void debug() const {
        std::cout << "Quote:\nbookNo: " << bookNo
                  << "\nprice: " << price << std::endl;
    }
private:
    std::string bookNo;
protected:
    double price = 0.0;
};
#endif
