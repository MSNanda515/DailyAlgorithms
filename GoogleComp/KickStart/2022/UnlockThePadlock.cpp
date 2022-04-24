#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>
#include <limits.h>

using namespace std;

long findMinDist(const int& curVal, long targetVal, const int& d) {
    long d1, d2;
    if (targetVal >= curVal) {
        d1 = abs(targetVal - curVal);
        d2 = abs(curVal + d - targetVal);
        return min(d1, d2);
    }

    d1 = abs(targetVal - curVal);
    d2 = abs(d - curVal + targetVal);
    return min(d1, d2);
}

// invariant is that all elements from l to r inc have same values
void moves(int l, int r, vector<int>& pad, long& oper, const int& n, const int& d) {
    if (l == 0 && r == n - 1) {
        if (pad[0] != 0) {
            oper += findMinDist(pad[0], 0, d);
        } 
        return;
    }

    int distLeft = INT_MAX, distRight = INT_MAX;
    if (l > 0) {
        distLeft = findMinDist(pad[l], pad[l-1], d);
    }
    if (r < n - 1) {
        distRight = findMinDist(pad[r], pad[r+1], d);
    }
    if (distLeft < distRight) {
        oper += distLeft;
        for (int i = l; i <= r; i++) {
            pad[i] = pad[l-1];
        }
    } else {
        oper += distRight;
        for (int i = l; i <= r; i++) {
            pad[i] = pad[r+1];
        }
    }
    // expand l and r
    for (; l > 0 && pad[l] == pad[l-1]; l--);
    for (; r < n - 1 && pad[r] == pad[r+1]; r++);
    moves(l, r, pad, oper, n, d);
}

long sol(const int& n, const int& d, vector<int>& pad) {
    int i, j;
    long ans = __LONG_MAX__;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n && pad[i] == pad[j]; j++);
        vector<int> padTemp(pad);
        long oper = 0;
        moves(i, j-1, padTemp, oper, n, d);
        if (ans > oper) {
            ans = oper;
        }
    }
    return ans;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, d;
        cin >> n >> d;
        vector<int> pad(n);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            pad[i] = temp;
        }
        cout << "Case #" << i+1 << ": " << sol(n, d, pad) << '\n';
    }
}