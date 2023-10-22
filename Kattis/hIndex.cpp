#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>


using namespace std;

void sol() {
    int n;
    cin >> n;
    vector<int> cit(n);
    for (int i = 0; i < n; i++) {
        cin >> cit[i];
    }
    sort(cit.begin(), cit.end());
    int hind = 0;
    int lastVal = -1, i;
    for (i = 0; i < n; i++) {
        while (i < n && cit[i] <= lastVal) {
            i++;
        }
        if (i == n) { break; }
        int citGt = n - i;
        if (citGt >= cit[i]) {
            hind = cit[i];
        } else if (citGt > hind) {
            hind = citGt;
        }
        lastVal = cit[i];
    }
    cout << hind << '\n';
}

int main() {
    sol();
}