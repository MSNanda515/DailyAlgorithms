// https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Uses a monotonic increasing stack.
// at each pop, finds the area of the rectangle with the popped height as the smallest
// side

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> inc;
        int curAr, tp, maxAr = 0;
        int i = 0, n = heights.size();
        while (i < n) {
            if (inc.empty() || heights[inc.top()] <= heights[i]) {
                inc.push(i);
                i++;
            } else {
                tp = inc.top();
                inc.pop();
                curAr = heights[tp] *
                    (inc.empty() ? i : i - inc.top() - 1);
                maxAr = max(maxAr, curAr);
            }
        }
        
        while (!inc.empty()) {
            tp = inc.top();
            inc.pop();
            curAr = heights[tp] *
                (inc.empty() ? i : i - inc.top() - 1);
            maxAr = max(maxAr, curAr);
        }
        return maxAr;
    }
};