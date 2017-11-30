#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    cout << left << setw(20) << "default format: " << right << 100 * sqrt(2.0) << '\n'
         << left << setw(20) << "scientific: " << scientific << right << 100 * sqrt(2.0) << '\n'
         << left << setw(20) << "fixed_decimal: " << fixed << right << 100 * sqrt(2.0) << '\n'
         << left << setw(20) << "hexadecimal: " << hexfloat << right << 100 * sqrt(2.0) << '\n'
         << left << setw(20) << "use defaults: " << defaultfloat << right << 100 * sqrt(2.0) << "\n\n";
    return 0;
}
