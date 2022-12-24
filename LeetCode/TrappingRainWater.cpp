#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), lb, ub;
        vector<int> left (n, 0), right (n, 0);
        int maxLeft = height[0], maxRight = height[n-1];
        for (int i = 0; i < n; i++) {
            maxLeft = max(maxLeft, height[i]);
            maxRight = max(maxRight, height[n-i-1]);
            left[i] = maxLeft;
            right[n-i-1] = maxRight;
        }
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(left[i], right[i]) - height[i];
        }
        return water;
    }
};