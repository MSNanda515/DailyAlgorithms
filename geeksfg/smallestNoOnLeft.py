"""
Finds the closest smaller number to the left of the current number
Logic: Maintain a stack such that each element is the largest number to its left
    While adding a new number, remove all elements from the top that are greater than or equal to the current element
    The top of the stack gives the closest smaller element
    -1 if the stack is empty, which means this is the lowest element so far
"""

class Solution:
    def leftSmaller(self, n, a):
        # code here
        ans = [0 for i in range(n)]
        st = []
        for i in range(n):
            while len(st) > 0 and st[-1][0] >= a[i]:
                st.pop()
            if len(st) == 0:
                ans[i] = -1
            else:
                ans[i] = st[-1][0]
            st.append([a[i], i])
            # print(st)
        return ans
                
    