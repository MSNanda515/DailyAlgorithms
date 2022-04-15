// https://open.kattis.com/problems/basketballoneonone

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

string sol(string str) {
    bool du = false;
    int alice = 0, bob = 0;
    for (int i = 0; i < str.size(); i+=2) {
        char person = str[i];
        int score = str[i+1] - '0';
        switch (person) {
            case 'A':
                alice += score;
                break;
            case 'B':
                bob += score;
        }
    }
    if (bob > 11 || alice > 11) {
        if (bob > alice)
            return "B";
        else
            return "A";
    }
    if (bob == 11)
        return "B";
    else
        return "A";
}

int main() {
    string str;
    cin >> str;
    cout << sol(str) << '\n';
}