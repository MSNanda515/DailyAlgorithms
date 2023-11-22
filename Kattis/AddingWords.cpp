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

const string UNKNOWN = "unknown";

void printCalcAnswer(vector<string>& tokens, string ans) {
    for (int i = 1; i < tokens.size(); i++) {
        cout << tokens[i] << " ";
    }
    cout << ans << "\n";
}

void calc(vector<string>& tokens, unordered_map<string, int>& mem, unordered_map<int, string>& memRev) {
    if (tokens.size() == 2) {
        printCalcAnswer(tokens, UNKNOWN);
        return;
    }
    if (mem.find(tokens[1]) == mem.end()) {
        printCalcAnswer(tokens, UNKNOWN);
        return;
    }

    long ans = mem[tokens[1]];
    int num = 0;
    for (int i = 2; i < tokens.size(); i+=2) {
        if (tokens[i] == "=") { break; }
        if (mem.find(tokens[i+1]) == mem.end()) {
            printCalcAnswer(tokens, UNKNOWN);
            return;
        }
        num = mem[tokens[i+1]];
        if (tokens[i] == "+") {
            ans += num;
        } else {
            ans -= num;
        }
    }

    if (memRev.find(ans) == memRev.end()) {
        printCalcAnswer(tokens, UNKNOWN);
        return;
    }
    printCalcAnswer(tokens, memRev[ans]);
}

void processCommand(string& line, unordered_map<string, int>& mem, unordered_map<int, string>& memRev) {
    istringstream tokenizer(line);
    vector<string> tokens;
    string token;
    while (tokenizer >> token) {
        tokens.push_back(token);
    }
    if (tokens.size() == 0) { return; }
    int num;
    if (tokens[0] == "def") {
        num = stoi(tokens[2]);
        mem[tokens[1]] = num;
        memRev[num] = tokens[1];
    } else if (tokens[0] == "calc") {
        calc(tokens, mem, memRev);
    } else {
        mem.clear();
        memRev.clear();
    }
}

void sol() {
    string line;
    unordered_map<string, int> mem;
    unordered_map<int, string> memRev;
    while (getline(cin, line)) {
        processCommand(line, mem, memRev);
    }
}

int main() {
    sol();
}