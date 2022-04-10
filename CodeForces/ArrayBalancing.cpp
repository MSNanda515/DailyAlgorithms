#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;

long long findAdd(int ind, vector<int>& a, vector<int>& b) {
    long long ans = 0;
    if (ind > 0) {
        ans += abs(a[ind] - a[ind-1]);
        ans += abs(b[ind] - b[ind-1]);
    }
    // if (ind < a.size()-1) {
    //     ans += abs(a[ind] - a[ind+1]);
    //     ans += abs(b[ind] - b[ind+1]);
    // }
    return ans;
}

void swapInd(int ind, vector<int>& a, vector<int>& b) {
    int temp = a[ind];
    a[ind] = b[ind];
    b[ind] = temp;
}

long long recurse(int ind, vector<int>& a, vector<int>& b, long long sumSoFar) {
    if (ind == a.size())
        return sumSoFar;
    
    long long sumCase1 = findAdd(ind, a, b);
    sumCase1 = recurse(ind+1, a, b, sumSoFar + sumCase1);

    swapInd(ind, a, b);
    long long sumCase2 = findAdd(ind, a, b);
    sumCase2 = recurse(ind+1, a, b, sumSoFar + sumCase2);
    swapInd(ind, a, b);

    if (sumCase1 < sumCase2) {
        return sumCase1;
    }
    return sumCase2;
}

long long sol(vector<int>& a, vector<int>& b) {
    return recurse(0, a, b, 0ll);
}

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            a[i] = temp;
        }
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            b[i] = temp;
        }
        cout << sol(a, b) << '\n';
    }
}