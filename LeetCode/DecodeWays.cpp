// https://leetcode.com/problems/decode-ways/description/
// Uses dp to count total ways of decoding the given string

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    int decode(string& s, int i, vector<int>& dp) {
        if (i >= s.size()) {
            return 1;
        }
        if (dp[i] >= 0) {
            return dp[i];
        }
        int ans = 0;
        if (s[i] == '0') {
            ans = 0;
        } else if (i == s.size()-1) {
            ans = 1;
        } else {
            int a = stoi(s.substr(i, 2));
            ans = 0;
            if (s[i+1] != '0') {
                ans += decode(s, i + 1, dp);
            } 
            if (a > 0 && a <= 26) {
                ans += decode(s, i+2, dp);
            }
        }
        dp[i] = ans;
        return ans;
    }
public:
    int numDecodings(string s) {
        vector<int> dp (s.size(), -1);
        return decode(s, 0, dp);
    }
};