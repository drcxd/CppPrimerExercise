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
        for (sregex_iterator it(content.begin(), content.end(), r), end;
             it != end; ++it) {
            cout << it->str() << endl;
        }
        // if (regex_search(content, result, r)) {
        //     cout << "match found: " << result.str() << endl;
        // }
    }
    
    
    return 0;
}
