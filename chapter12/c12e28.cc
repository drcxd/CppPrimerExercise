#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <sstream>

using namespace std;

void read_file(ifstream &input, vector<string> &text);
void query(const string &query_word,
    const vector<string> &text,
    map<string, set<int>> &word_line_map,
    map<string, int> &word_count_map);
void print(const string &query_word,
    const vector<string> &text,
    const map<string, set<int>> &word_line_map,
    const map<string, int> &word_count_map);

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "usage: main.exe <filename>\n";
        return 0;
    }

    ifstream input(argv[1]);
    if (!input.good()) {
        cout << "cannot open file " << argv[1] << endl;
        return 0;
    }
    vector<string> text;
    read_file(input, text);
    map<string, set<int>> word_line_map;
    map<string, int> word_count_map;
    while (true) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") {
            break;
        }
        query(s, text, word_line_map, word_count_map);
        print(s, text, word_line_map, word_count_map);
    }

    return 0;
}

void read_file(ifstream &input, vector<string> &text) {
    string line;
    while (getline(input, line)) {
        text.push_back(line);
    }
}

void query(const string &query_word,
    const vector<string> &text,
    map<string, set<int>> &word_line_map,
    map<string, int> &word_count_map) {
    auto beg = text.begin();
    auto end = text.end();
    int line_number = 1;
    for ( ; beg != end; ++beg) {
        istringstream line(*beg);
        string word;
        while (line >> word) {
            if (word == query_word) {
                ++word_count_map[word];
                word_line_map[word].insert(line_number);
            }
        }
        ++line_number;
    }
}

void print(const string &query_word,
    const vector<string> &text,
    const map<string, set<int>> &word_line_map,
    const map<string, int> &word_count_map) {
    if (word_count_map.find(query_word) == word_count_map.end()) {
        cout << "no such word: " << query_word << endl;
    }
    cout << query_word << " occurs " << word_count_map.find(query_word)->second
         << "times\n";
    auto beg = word_line_map.find(query_word)->second.begin();
    auto end = word_line_map.find(query_word)->second.end();
    for ( ; beg != end; ++beg) {
        cout << "(line " << *beg << ") " << text[*beg - 1] << endl;
    }
}
