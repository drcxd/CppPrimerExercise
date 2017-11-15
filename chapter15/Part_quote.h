#pragma once
#ifndef _PART_QUOTE_H
#define _PART_QUOTE_H

#include "Disc_quote.h"

class Part_Quote : public Disc_quote {
    Part_Quote = default;
    Part_Quote(const std::string &bookNo, double price, std::size_t quantity, double discount);
    double net_price(std::size_t quantity) const override;
    void debug() const override {
        std::cout << "Part_Quote:\nmax_qty: " << quantity
                  << "\ndiscount: " << discount << std::endl;
    }
};
#endif
