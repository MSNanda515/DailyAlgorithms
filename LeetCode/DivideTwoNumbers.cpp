// https://leetcode.com/problems/divide-two-integers/description/
// Founds each bit of the the answer at a time
// uses shift operator to multiply by 2 gradually

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (dividend == divisor) return 1;
        int fact = (dividend > 0 == divisor > 0);
        unsigned int a = abs(dividend);
        unsigned int b = abs(divisor);
        unsigned int ans = 0;
        while (a >= b) {
            short q = 0;
            while (a > (b << (q+1)))
                q += 1;
            ans += (1 << (q));
            a -= (b << q);
        }
        if (ans == (1 << 31) && fact) {
            return INT_MAX;
        }
        return fact ? ans : -ans;
    }
};