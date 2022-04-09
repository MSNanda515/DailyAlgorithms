#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>


using namespace std;

long long unAccFun = 0;

long long traverse(int& cur, vector<int>& funFact, vector<int>& point, int& n, unordered_map<int, vector<int>>& rec, unordered_set<int>& init) {
    if (init.find(cur) != init.end()) {
        return funFact[cur - 1];
    }
    vector<long long> funTemp;
    long long minFunTemp = __LONG_LONG_MAX__, funSoFar = 0;
    for (int i = 0; i < rec[cur].size(); i++) {
        funTemp.push_back(traverse(rec[cur][i], funFact, point, n, rec, init));
        if (minFunTemp > funTemp.back()) {
            minFunTemp = funTemp.back();
        }
    }

    long long sumAllFun = 0;
    for (int i = 0; i < funTemp.size(); i++) {
        sumAllFun += funTemp[i];
    }

    sumAllFun -= minFunTemp;
    unAccFun += sumAllFun;

    return max(minFunTemp, (long long)funFact[cur-1]);
}

void sol(vector<int>& funFact, vector<int>& point, int &n) {
    unordered_map<int, vector<int>> rec;
    for (int i = 0; i < n; i++) {
        rec[point[i]].push_back(i+1);
    }
    unordered_set<int> init;
    for (int i = 1; i <= n; i++) {
        if (rec.find(i) == rec.end()) {
            init.insert(i);
        }
    }

    unAccFun = 0;
    long long totFun = 0;
    for (int i = 0; i < rec[0].size(); i++) {
        totFun += traverse(rec[0][i], funFact, point, n, rec, init);
    }
    cout << totFun + unAccFun << '\n';
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int n, temp;
        cin >> n;
        vector<int> funFact, point;

        for (int i = 0; i < n; i++) {
           cin >> temp;
           funFact.push_back(temp);
        }
        for (int i = 0; i < n; i++) {
            cin >> temp;
            point.push_back(temp);
        }

        cout << "Case #" << k + 1 << ": ";
        sol(funFact, point, n);
    }
}