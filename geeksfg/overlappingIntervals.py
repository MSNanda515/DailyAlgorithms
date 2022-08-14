# https://practice.geeksforgeeks.org/problems/8a644e94faaa94968d8665ba9e0a80d1ae3e0a2d/1
# Logic: Sort the array, find the intersections. Whenever starting a new interval, store the previous interval
class Solution:
    def overlappedInterval(self, Intervals):
        #Code here
        ans = []
        Intervals.sort()
        curBeg = Intervals[0][0]
        curEnd = Intervals[0][1]
        for i in range(0, len(Intervals)):
            if curEnd < Intervals[i][0]:
                ans.append([curBeg, curEnd])
                [curBeg, curEnd] = Intervals[i]
            else:
                curEnd = max(curEnd, Intervals[i][1])
        ans.append([curBeg, curEnd])
        return ans