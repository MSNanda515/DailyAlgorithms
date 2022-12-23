// https://leetcode.com/problems/first-missing-positive/description/
// Puts each positive number in the correct spot, then starts iterating from start
// and finds the first missing positive number

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) {
                return i+1;
            }
        }
        return n+1;
    }
};