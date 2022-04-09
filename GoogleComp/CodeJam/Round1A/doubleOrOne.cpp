#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

string sol(string str) {
    string ans = "";
    int i = 0;
    for (; i < str.size(); i++) {
        if (i == str.size() - 1) {
            ans.push_back(str[i]);
            continue;
        }
        if (str[i] < str[i+1]) {
            ans.push_back(str[i]);
            ans.push_back(str[i]);
        } else if (str[i] == str[i + 1]) {
            bool rep = false;
            int j = i + 1;
            for (; j < str.size(); j++) {
                if (str[i] == str[j])
                    continue;
                // if (j == str.size() - 1) {
                //     break;
                // }
                if (str[i] < str[j]) {
                    rep = true;
                    break;
                }
                else 
                    break;
            }
            if (rep) {
                for (; i < j; i++) {
                    ans.push_back(str[i]);
                    ans.push_back(str[i]);
                }
            }
            else {
                for (; i < j; i++) {
                    ans.push_back(str[i]);
                }
            }
            i--;
        } else {
            ans.push_back(str[i]);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        string str;
        cin >> str;
        cout << "Case #" << k + 1 << ": " << sol(str) << '\n';
    }
}