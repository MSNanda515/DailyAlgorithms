# Generalize solution to k sum.
# Complexity : O(n^(k-1)). Uses 2 sum at the last iteration
# Uses recursion to simulate k - 2 embedded loops

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        return self.kSum(nums, 0, 4, target)
        pass
    
    def kSum(self, nums, ind, k, target):
        ans = []
        n = len(nums)
        if (ind == n):
            return ans
        if k == 2:
            return self.twoSum(nums, ind, target)
        

        avgVal = target // k
        if (nums[ind] > avgVal or nums[n - 1] < avgVal):
            return ans
        
        for i in range(ind, n):
            if (i == ind or nums[i] != nums[i-1]):
                tempAns = self.kSum(nums, i+1, k-1, target-nums[i])
                for j in range(len(tempAns)):
                    ans.append([nums[i]])
                    for t in tempAns[j]:
                        ans[-1].append(t)
        return ans
        pass
    
    def twoSum(self, nums, ind, target):
        lb = ind
        ub = len(nums) - 1
        ans = []
        while (lb < ub):
            if (lb > ind and nums[lb] == nums[lb-1]):
                lb += 1
                continue
            tempSum = nums[lb] + nums[ub]
            if tempSum == target:
                ans.append([nums[lb], nums[ub]])
                lb += 1
            elif tempSum > target:
                ub -= 1
            else:
                lb += 1
        return ans