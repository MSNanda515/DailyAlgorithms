// https://leetcode.com/problems/container-with-most-water/description/
// uses greedy algorithm; two pointers; move that pointer which is of smaller length since
// capacity limited by side with min length
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0, tempArea;
        int lb = 0, ub = height.size() - 1;
        while (lb < ub) {
            tempArea = (ub-lb) * min(height[lb], height[ub]);
            if (tempArea > area)
                area = tempArea;
            if (height[lb] < height[ub]) {
                lb += 1;
            } else {
                ub -= 1;
            }
        }
        return area;
    }
};
