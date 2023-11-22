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

int findCocRet(const int& timeAvail, const vector<int>& a, const vector<int>& b, const int& n) {
    int cocRet = 0;
    for (int i = 0; i < n; i++) {
        if (timeAvail < a[i]) { continue; }
        cocRet += (timeAvail - a[i]) / b[i] + 1;
    }
    return cocRet;
}

int findCocBrok(const int& timeAvail, const vector<int>& c, const vector<int>& d, const int& m) {
    int cocBrok = 0;
    for (int i = 0; i < m; i++) {
        if (timeAvail < c[i]) { continue; }
        cocBrok += (timeAvail - c[i]) / d[i] + 1;
    }
    return cocBrok;
}

int findSplitTime(int lo, int hi, const vector<int>& a, const vector<int>& b, const vector<int>& c, const vector<int>& d, const int& n, const int& m) {
    int timeAvail, cocRet, cocBrok;
    int totTime = hi;
    while (hi - lo > 1) {
        timeAvail = (lo + hi) / 2;
        cocRet = findCocRet(timeAvail, a, b, n);
        cocBrok = findCocBrok(totTime - timeAvail, c, d, m);
        if (cocRet > cocBrok) { hi = timeAvail; }
        else { lo = timeAvail; }
    }
    return lo;
}


void sol() {
    int tottime;
    cin >> tottime;
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    cin >> m;
    vector<int> c(m), d(m);
    for (int i = 0; i < m; i++) {
        cin >> c[i] >> d[i];
    }
    cout << findSplitTime(0, tottime, a, b, c, d, n, m) << endl;
}

int main() {
    sol();
}