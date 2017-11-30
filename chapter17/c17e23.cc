#include <regex>
#include <string>
#include <iostream>

using namespace std;

int main() {
    regex r("\\d{5}(-?\\d{4})?\\z");
    string zipcode = "";
    smatch result;
    while (zipcode != "q") {
        cin >> zipcode;
        if (regex_search(zipcode, result, r)) {
            cout << result.str() << endl;
        }
    }    
    return 0;
}
