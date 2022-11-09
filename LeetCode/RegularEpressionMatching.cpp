// https://leetcode.com/problems/regular-expression-matching/description/
// Use dynamic programming because overlapping subproblems

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<bool>> dp (n+1, (vector<bool>(m+1, false)));
        bool posMatch = true;
        dp[n][m] = true;
        for (int i = n; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                posMatch = false;
                if (i < n && (s[i] == p[j] || p[j] == '.')) {
                    posMatch = true;
                }

                if (j + 1 < m && p[j+1] == '*') {
                    // consider 0 or more from string
                    dp[i][j] = dp[i][j+2] || (posMatch && dp[i+1][j]);
                } else {
                    // current match plus the following pattern
                    dp[i][j] = posMatch && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};