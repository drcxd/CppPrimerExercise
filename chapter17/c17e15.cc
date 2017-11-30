#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    regex r("\\w*[^c]ei\\w*");
    smatch result;
    string content = "";
    while (content != "q") {
        cout << "input a string or q to quit: ";
        getline(cin, content);
        if (regex_search(content, result, r)) {
            cout << "match found: " << result.str() << endl;
        }
    }
    
    
    return 0;
}
