// https://leetcode.com/problems/jump-game/
// Uses dp, O(n), goes to each index at most 1

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    bool canJump(vector<int>& nums, int cur, vector<short>& dp) {
        if (dp[cur] >= 0) {
            return dp[cur];
        }
        if (cur == nums.size()-1) {
            dp[cur] = true;
            return true;
        }
        if (nums[cur] <= 0) {
            dp[cur] = false;
            return false;
        }
        bool jump = false;
        for (int i = 1; i <= nums[cur]; i++) {
            jump = canJump(nums, cur+i, dp);
            if (jump) {
                break;
            }
        }
        dp[cur] = jump;
        return jump;
    }

public:
    bool canJump(vector<int>& nums) {
        vector<short> dp (nums.size(), -1);
        return canJump(nums, 0, dp);
    }
};