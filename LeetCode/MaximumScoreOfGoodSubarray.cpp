class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int lb = k, ub = k;
        int score = nums[k];
        int tempScore;
        int minNo = nums[k];
        while (lb > 0 && ub < nums.size()-1) {
            if (nums[lb-1] > nums[ub+1]) {
                lb--;
                minNo = min(minNo, nums[lb]);
            } else if (nums[lb-1] == nums[ub+1]) {
                lb--;
                ub++;
                minNo = min(minNo, nums[lb]);
            } else{
                ub++;
                minNo = min(minNo, nums[ub]);
            }
            tempScore = minNo * (ub - lb + 1);
            score = max(score, tempScore);
        }
        while (lb >= 0) {
            minNo = min(minNo, nums[lb]);
            score = max(score, minNo * (ub - lb + 1));
            lb--;
        }
        lb = 0;
        while (ub < nums.size()) {
            minNo = min(minNo, nums[ub]);
            score = max(score, minNo * (ub - lb + 1));
            ub++;
        }
        return score;
    }
};