#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename T>
int count(const T &val, const vector<T> &v) {
    int result = 0;
    for (const auto &i : v) {
        if (i == val) {
            ++result;
        }
    }
    return result;
}

int main() {
    vector<int> iv = {0, 1, 2, 3, 1, 2, 1};
    vector<double> dv = {0.1, 0.2, 0.3, 0.1, 0.2 ,0.2};
    vector<string> sv = {"one", "two", "one", "two", "three"};
    cout << count(1, iv) << endl;
    cout << count(0.2, dv) << endl;
    cout << count(string("three"), sv) << endl;
    return 0;
}
