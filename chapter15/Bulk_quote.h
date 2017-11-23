#pragma once
#ifndef _BULK_QUOTE_H
#define _BULK_QUOTE_H

#include "Disc_quote.h"

class Bulk_quote : public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    // Bulk_quote() = default;
    // Bulk_quote(const std::string&, double, std::size_t, double);
    // Bulk_quote(const Bulk_quote &bq) : Disc_quote(bq) {
    //     std::cout << "Bulk_quote copy constructor is called\n";
    // }
    Bulk_quote &operator=(const Bulk_quote &rhs) {
        Quote::operator=(rhs);
        Disc_quote::operator=(rhs);
        std::cout << "Bulk_quote copy-assignment operator is called\n";
        return *this;
    }
    double net_price(std::size_t) const override;
    // void debug() const override {
    //     std::cout << "Bulk_quote:\nmin_qty: " << quantity
    //               <<"\ndiscount: " << discount << std::endl;
    // }
    ~Bulk_quote() override {
        std::cout << "Bulk_quote destructor is called\n";
    }
};
#endif
