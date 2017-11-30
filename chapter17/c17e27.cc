#include <regex>
#include <string>
#include <iostream>

using namespace std;

int main() {
    regex r("(\\d{5})-?(\\d{4})");
    string zipcode = "";
    string output = "$1-$2";    
    smatch result;
    while (zipcode != "q") {
        cin >> zipcode;
        if (regex_search(zipcode, result, r)) {
            cout << "matched\n";
        }
        cout << regex_replace(zipcode, r, output) << endl;
    }
    return 0;
}
