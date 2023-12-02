#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <sstream>


using namespace std;

bool isDig(char ch) {
    return ch >= '0' && ch <= '9';
}

int isDig(string str, unordered_map<string, int> digs) {
    if (str.size() == 1) {
        return isDig(str[0]) ? str[0] - '0' : -1;
    }
    if (digs.find(str) != digs.end()) {
        return digs[str];
    }
    return -1;
}

unordered_map<string, int> getDigsMap() {
    return {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
        {"zero", 0}
    };
}

void sol() {
    string input;
    long cum = 0;
    unordered_map<string, int> digs = getDigsMap();
    while (getline(cin, input)) {
        int val = 0;
        int temp = -1;
        for (int i = 0; i < input.size(); i++) {
            for (int j = i; j < input.size(); j++) {
                temp = isDig(input.substr(i, j-i+1), digs);
                if (temp >= 0) {
                    // cout << temp << " ";
                    val = temp;
                    break;
                }
            }
            if (temp >= 0) { break; }
        }
        val *= 10;
        temp = -1;
        for (int i = input.size()-1; i >= 0; i--) {
            for (int j = i; j < input.size(); j++) {
                temp = isDig(input.substr(i, j-i+1), digs);
                if (temp >= 0) {
                    // cout << temp << " ";
                    val += temp;
                    break;
                }
            }
            if (temp >= 0) { break; }
        }
        // cout << val << endl;
        cum += val;
    }
    cout << cum << endl;
}

int main() {
    sol();
}