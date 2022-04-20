// https://cses.fi/problemset/task/1640/
// Sorts the array keeping track of the final and the initial index of each value
// use two pointers, one initialized at the first element and the second at the last
// Modify the pointers based on the current sum

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

void printSol(int x, int y) {
    cout << x << ' ' << y  << '\n';
}

struct pack {
    int val, ind;
};

bool compPack(pack& p1, pack& p2) {
    return p1.val < p2.val;
}

void sol(vector<pack>& num, int x) {
    sort(num.begin(), num.end(), compPack);
    int lb = 0, ub = num.size()-1;
    while (lb < ub) {
        long tempSum = num[lb].val + num[ub].val;
        if (tempSum == x) {
            printSol(num[lb].ind, num[ub].ind);
            return;
        } else if (tempSum > x) {
            ub--;
        } else {
            lb++;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<pack> num;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        num.push_back({temp, i+1});
    }
    sol(num, x);
}