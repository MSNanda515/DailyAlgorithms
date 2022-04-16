class Solution:
    def solveWordWrap(self, nums, k):
        # Code here
        n = len(nums)
        dp = [0] * n
        ans = [0] * n

        dp[n-1] = 0
        ans[n-1] = n-1

        for i in range(n-2, -1, -1):
            curLen = -1
            dp[i] = 1e9

            for j in range(i, n):
                curLen += (nums[j] + 1)
                if curLen > k:
                    break
                if j == n-1:
                    cost = 0
                else:
                    cost = (k - curLen) * (k - curLen) + dp[j+1]

                if dp[i] > cost:
                    dp[i] = cost
                    ans[i] = j

        return dp[0]

# {
#  Driver Code Starts
# Initial Template for Python 3


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        nums = list(map(int, input().split()))
        k = int(input())
        obj = Solution()
        ans = obj.solveWordWrap(nums, k)
        print(ans)
