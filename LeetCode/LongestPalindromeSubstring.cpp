// https://leetcode.com/problems/longest-palindromic-substring/
// Uses Dynamic Programming, to keep track of whether Si...Sj is palindrome
// Uses this information to find whether Si-1...Sj+1 is a palindrome
// Could be done in n^3 using brute force, find all the substrings and then whether they are 
// palindrome or not. Using dp eliminate the inner most loop

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        string maxSubstr = "" + s.substr(0, 1);
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0; i + gap < n; i++) {
                int endI = i + gap;
                if (i == endI) {
                    dp[i][endI] = true;
                } else if (s[i] == s[endI]) {
                    if (endI == i+1 || dp[i+1][endI-1]) {
                        dp[i][endI] = true;
                    }
                }
            }
        }
        for (int gap = n-1; gap >= 0; gap--) {
            for (int start = 0; start + gap < n; start++) {
                if (dp[start][start+gap] == true) {
                    maxSubstr = s.substr(start, gap+1);
                    return maxSubstr;
                    break;
                }
            }
        }
        return maxSubstr;
    }
};