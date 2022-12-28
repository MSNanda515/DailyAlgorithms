// https://leetcode.com/problems/subsets/description/
// Subsets, find all subsets by either adding or not adding an item
// Alternative solution, iterate through all n bit numbers, add a 
// digit if bit is set for that position
// does not require iteration, binary operations

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
    void subsets(vector<vector<int>>& superset, vector<int>& buff, vector<int>& nums, int ind) {
        if (ind == nums.size()) {
            superset.push_back(buff);
            return;
        }
        subsets(superset, buff, nums, ind+1);
        buff.push_back(nums[ind]);
        subsets(superset, buff, nums, ind+1);
        buff.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> superset;
        vector<int> buffer;
        subsets(superset, buffer, nums, 0);
        return superset;
    }
};