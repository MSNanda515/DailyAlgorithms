#include <iostream>
#include <vector>

using namespace std;

void transferHanoi(int n, string from, string to, string left, vector<string>& ans) {
    string temp;
    if (n == 1) {
        temp = "" + from + " " + to + "\n";
        ans.push_back(temp);
        return;
    }
    transferHanoi(n-1, from, left, to, ans);
    temp = "" + from + " " + to + "\n";
    ans.push_back(temp);
    transferHanoi(n-1, left, to, from, ans);
}

int main() {
    int n;
    cin >> n;
    vector<string> ans;
    transferHanoi(n, "1", "3", "2", ans);
    cout << ans.size() << '\n';
    for (auto t : ans) {
        cout << t;
    }
}