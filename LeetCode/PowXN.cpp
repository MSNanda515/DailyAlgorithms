// https://leetcode.com/problems/powx-n/submissions/864942634/
// Double the power every time if can,
// uses log2(n) complexity
// divides the n by 2 during each iteration

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            x = 1 / x;
            n = abs(n);
        }
        double xOrig = x;
        unsigned int cur = 1;
        while (cur < n) {
            if (2 * cur <= n) {
                x = x * x;
                cur = cur * 2;
            } else {
                x = x * myPow(xOrig, n - cur);
                cur = n;
            }
        }
        return x;
    }
};