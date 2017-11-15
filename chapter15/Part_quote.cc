#include "Part_quote.h"

Part_Quote::Part_Quote(const std::string &bookNo,
    double price, std::size_t qty, double disc)
    : Disc_quote(bookNo, price, qty, disc) { }

double Part_Quote::net_price(std::size_t qty) const {
    if (qty <= quantity) {
        return qty * (1 - discount) * price;
    } else {
        std::size_t surplus = qty - quantity;
        return max_qty * (1 - discount) * price + surplus * price;
    }
}
