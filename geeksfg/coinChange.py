# https://practice.geeksforgeeks.org/problems/coin-change2448/1
"""
For each coin, for all currencies starting from that coin, find the number of ways different amounts can be 
formed adding that coint to previous computed amounts
"""

class Solution:
    
    def count(self, S, m, n): 
        # code here 
        cur = [0 for i in range(0, n+1)]
        cur[0] = 1
        for i in range(0, m):
            for j in range(S[i], n+1):
                cur[j] += cur[j - S[i]]
        
        return cur[n]
        


import sys
sys.setrecursionlimit(10**6)

if __name__ == '__main__': 
    t = int(input())
    for _ in range(t):
        n,m = list(map(int, input().strip().split()))
        S = list(map(int, input().strip().split()))
        ob = Solution()
        print(ob.count(S,m,n))