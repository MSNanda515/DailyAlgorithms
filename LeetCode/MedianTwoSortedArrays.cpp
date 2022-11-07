// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
// Divide the two arrays such that half number of elements in each half for both arrays
// find that half that would include the mean

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(); 
        int n2 = nums2.size();
        if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

        int lo = 0, hi = n1;
        while (lo <= hi) {
            int cut1 = (lo + hi) /2;
            int cut2 = (n1 + n2 + 1) / 2 - cut1;

            int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (l1 <= r2 && l2 <= r1) {
                if ((n1 + n2) % 2 == 0) {
                    return 1.0 * (max(l1, l2) + min(r1, r2)) / 2;
                } else {
                    return max(l1, l2);
                } 
            } else if (l1 > r2) {
                hi = cut1 - 1;
            } else {
                lo = cut1 + 1;
            }
        }
        return 0.0;
    }
};