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

void processLine(string& input, long& cum) {
    stringstream ss(input);
    string token;
    unordered_set<int> winning;
    int match = 0;
    int temp = 0;
    bool winningMode = true;
    long score = 0;
    while (getline(ss, token, ' ')) {
        if (token.empty()) { continue; }
        temp++;
        // cout << token << "\n";
        if (temp < 3) { continue; }
        if (winningMode) {
            // first half
            if (token[0] == '|') {
                winningMode = false;
                continue;
            }
            winning.insert(stoi(token));
        } else {
            if (winning.find(stoi(token)) == winning.end()) { continue; }
            match++;
            if (match == 1) { score = 1; } 
            else { score *= 2; }
        }
    }
    cum += score;
}

void processLine2(string& input, vector<int>& win) {
    stringstream ss(input);
    string token;
    unordered_set<int> winning;
    int temp = 0;
    int match = 0;
    bool winningMode = true;
    while (getline(ss, token, ' ')) {
        if (token.empty()) { continue; }
        temp++;
        if (temp < 3) { continue; }
        if (winningMode) {
            // first half
            if (token[0] == '|') {
                winningMode = false;
                continue;
            }
            winning.insert(stoi(token));
        } else {
            if (winning.find(stoi(token)) == winning.end()) { continue; }
            match++;
        }
    }
    win.push_back(match);
}

long countCards(vector<int>& win) {
    vector<int> cards(win.size(), 1);
    for (int i = 0; i < win.size(); i++) {
        for (int j = i + 1; j <= i + win[i] && j < cards.size(); j++) {
            cards[j] += cards[i];
        }
    }
    long totCards = 0;
    for (int i = 0; i < cards.size(); i++) {
        totCards += cards[i];
    }
    return totCards;
}

void sol() {
    string input;
    long cum = 0;
    vector<int> win;
    while (getline(cin, input)) {
       processLine2(input, win);
    }
    cout << countCards(win) << endl;
}

int main() {
    sol();
}