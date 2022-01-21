#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool satisfied(const long& app, const long& pre, const long& k) {
    if (app <= pre + k && app >= pre - k) {
        return true;
    }
    return false;
}

int main() {
    int n, m;
    long k, temp;
    cin >> n >> m >> k;
    vector<long> pre;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        pre.push_back(temp);
    }
    vector<long> app;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        app.push_back(temp);
    }
    sort(pre.begin(), pre.end());
    sort(app.begin(), app.end());
    auto preP = pre.begin();
    auto appP = app.begin();
    int sat = 0;
    while (preP != pre.end() && appP != app.end()) {
        if (*appP < *preP - k) {
            appP++;
        }
        else if (*appP > *preP + k) {
            preP++;
        }
        else {
            sat++;
            appP++;
            preP++;
        }
    }
    cout << sat << '\n';

}