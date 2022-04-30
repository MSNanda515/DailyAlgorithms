#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>

using namespace std;

string sol() {
}

bool isTowerValid(string& t) {
    unordered_set<char> charSeen;
    for (int i = 0; i < t.size(); i++) {
        if (charSeen.find(t[i]) != charSeen.end() && t[i-1] != t[i]) {
            return false;
        }
    }
    return true;
}

void combineTowers(string& t1, string &t2, vector<string>& combT) {
    string tc1 = t1 + t2;
    string tc2 = t2 + t1;
    if (isTowerValid(tc1)) {
        combT.push_back(tc1);
    }
    if (isTowerValid(tc2)) {
        combT.push_back(tc2);
    }
}

bool combineTowers(vector<string>& towers) {
    for (int i = 0; i < towers.size(); i++) {
        for (int j = i+1; j < towers.size(); j++) {
            
        }
    }
}

bool sol(int n, vector<string>& towers) {

}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        vector<string> towers;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            towers.push_back(temp);
        }
        string ans = sol();
        cout << "Case #" << i+1 << ": " << ans << '\n';
    }
}