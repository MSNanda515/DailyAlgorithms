// https://practice.geeksforgeeks.org/problems/k-ary-tree1235/1#
// Uses the Binary exponentiation algorithm to compute a^n in log(n)
// complexity
// Implemented in both recursive and iterative approach

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    long long karyTree(int k, int m) {
        // code here
        if (m == 0) {
            return 1ll;
        }
        long long mod = 1e9 + 7;
        long long res = karyTree(k, m/2);
        if (m % 2 != 0) {
            return (((res * res) % mod) *  k) % mod;
        }
        return (res * res) % mod;
    }

    long long karyTreeIterative(int k, int m) {
        long long mod = 1e9 + 7;
        long long ans = 1;
        long long prog = k;
        while (m > 0) {
            if (m & 1) {
                ans = (ans * prog) % mod; 
            }
            prog = (prog * prog) % mod;
            m >>= 1;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k,m;
        
        cin>>k>>m;

        Solution ob;
        cout << ob.karyTree(k,m) << endl;
    }
    return 0;
}