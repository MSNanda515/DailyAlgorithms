#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>

using namespace std;

void getCombinations(vector<char>& seq, unordered_map<int, char>& left, const int& n,
                     set<string>& ans) {
    int remInd = n - left.size();
    if (remInd == n - 1) {
        seq[remInd] = left.begin()->second;
        string temp = "";
        for (char c : seq)
            temp += c;
        ans.insert(temp);
        return;
    }
    vector<int> tempLeftSeq;
    for (auto it=left.begin(); it!=left.end(); it++) {
        tempLeftSeq.push_back(it->first);
    }
    for (int key : tempLeftSeq) {
        int val = left[key];
        seq[remInd] = val;
        left.erase(key);
        getCombinations(seq, left, n, ans);
        left[key] = val;
    }
}

int main() {
    string str;
    cin >> str;
    unordered_map<int, char> left;
    vector<char> seq;
    set<string> ans;
    for (int i = 0; i < str.size(); i++) {
        seq.push_back(' ');
        left[i] = str[i];
    }
    getCombinations(seq, left, str.size(), ans);
    cout << ans.size() << '\n';
    for (string s : ans) {
        cout << s << '\n';
    }
}