#include "TextQuery.h"
#include "QueryResult.h"

#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream input("input.txt");
    TextQuery tq(input);
    cout << "TextQuery initialized\n";
    while (true) {
        cout << "enter word to look for, or q to quit: " << endl;
        string s;
        if (!(cin >> s) || s == "q") {
            break;
        }
        QueryResult::print(cout, tq.query(s)) << endl;
    }
}
