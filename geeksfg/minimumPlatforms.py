# https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1?page=1&company[]=Amazon&curated[]=1&sortBy=submissions
"""
Logic:
Sort the order in which the trains arrive. Whenever a new train arrives, make sure that the trains that were supposed to leave
before the concerned arrival time have left. Give the arrived train any available platform. If no platform available, allocate
a new platform. Return the count of the min platforms required
"""


import heapq as hq

class Solution:    
    #Function to find the minimum number of platforms required at the
    #railway station such that no train waits.
    def minimumPlatform(self,n,arr,dep):
        # code here
        trains = [[arr[i], dep[i]] for i in range(0, n)]
        trains.sort()
        depq = []
        tracks = 1
        avail = 1
        
        for tr in trains:
            come = tr[0]
            leave = tr[1]
            while len(depq) > 0 and depq[0] < come:
                hq.heappop(depq)
                avail += 1
            if avail > 0:
                avail -= 1
            else:
                tracks += 1
            
            hq.heappush(depq, leave)
        return tracks


#{ 
 # Driver Code Starts
#Initial Template for Python 3
import atexit
import io
import sys

#Contributed by : Nagendra Jha


if __name__ == '__main__':
    test_cases = int(input())
    for cases in range(test_cases) :
        n = int(input())
        arrival = list(map(int, input().strip().split()))
        departure = list(map(int, input().strip().split()))
        ob=Solution()
        print(ob.minimumPlatform(n,arrival,departure))
# }
