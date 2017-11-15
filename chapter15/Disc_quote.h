#pragma once
#ifndef _DISC_QUOTE_H_
#define _DISC_QUOTE_H_

#include "Quote.h"

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(std::string bookNo, double price, std::size_t qty, double disc)
        : Quote(bookNo, price)
        , quantity(qty)
        , discount(disc) { }
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};
#endif
