// https://leetcode.com/problems/maximum-subarray/description/
// Use dp, at each index either add it to the running subarray, or have it by itself

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSum = max(curSum + nums[i], nums[i]);
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};