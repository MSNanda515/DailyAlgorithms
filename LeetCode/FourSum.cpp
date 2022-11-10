// https://leetcode.com/problems/4sum/discussion/
// Time complexity: O(n^3)
// similar to three sum with the last two digits found by two pointers

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int mid, lb4, ub4;
        long long req, tempSum;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }
            for (int j = i+1; j < nums.size(); j++) {
                if (j > i+1 && nums[j] == nums[j-1]) 
                    continue;
                req = long(target) - nums[i] - nums[j];
                lb4 = j + 1;
                ub4 = n - 1;
                while (lb4 < ub4) {
                    tempSum = nums[lb4] + nums[ub4];
                    if (tempSum < req) lb4 += 1;
                    else if (tempSum > req) ub4 -= 1;
                    else {
                        ans.push_back({nums[i], nums[j], nums[lb4], nums[ub4]});
                        lb4 += 1;
                        while (lb4 < ub4 && nums[lb4] == nums[lb4-1]) lb4 += 1;
                    }
                }
            }
        }
            
        return ans;
    }
};