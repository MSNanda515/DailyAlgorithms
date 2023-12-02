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

void sol() {
    string input;
    long cum = 0;
    while (getline(cin, input)) {
        int val = 0;
        for (int i = 0; i < input.size(); i++) {
            if (isDig(input[i])) {
                val = input[i] - '0';
                break;
            }
        }
        val *= 10;
        for (int i = input.size()-1; i >= 0; i--) {
            if (isDig(input[i])) {
                val += input[i] - '0';
                break;
            }
        }
        cum += val;
    }
    cout << cum << endl;
}

int main() {
    sol();
}