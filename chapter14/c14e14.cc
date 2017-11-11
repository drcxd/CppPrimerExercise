/* For operator+ have to make a copy to return. If we use operator+ to
 * implement operator +=, then operator+= have to make one copy. On
 * the other hand, operator+= don't have to make that extra copy.
 */


/* version 1 */
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum.units_sold += rhs.units_sold;
    sum.revenue += rhs.revenue;
    return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    *this = *this + rhs;
    return *this;
}

/* version 2 */
Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
    *this.units_sold += rhs.units_sold;
    *this.revenue += rhs.revenue;
    return *this;
}
