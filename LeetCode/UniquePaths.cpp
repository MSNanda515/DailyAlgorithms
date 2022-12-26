// https://leetcode.com/problems/unique-paths/
// Uses combinatorial logic, the most tricky part being to prevent overflow

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        int m1 = m-1, n1 = n-1, mn = m1+n1;
        long double mf1 = 1, nf1 = 1, mnf = 1, fact = 1;
        int m2 = max(m1, n1);
        int n2 = min(m1, n1);
        for (int i = m2+1; i <= mn; i++){
            mnf *= i;
        }
        for (int i = 1; i <= n2; i++) {
            nf1 *= i;
        }
        return mnf/nf1;
    }
};