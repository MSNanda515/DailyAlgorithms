# https://practice.geeksforgeeks.org/problems/maximum-of-all-subarrays-of-size-k3101/1
# Logic: Use a double ended que. Store only the significant (useful) indexes.
# Store only those indexes which are in the window and all the elements to the right of that element
# are smaller than it

from collections import deque

class Solution:
    
    #Function to find maximum of each subarray of size k.
    def max_of_subarrays(self,arr,n,k):
        qu = deque()
        
        # Insert the first k elements
        for i in range(k):
            # Remove all the elements from the right which are smaller than the currently selected element
            while qu and arr[i] >= arr[qu[-1]]:
                qu.pop()
            qu.append(i)
        
        ans = []
        for i in range(k, n):
            ans.append(arr[qu[0]])
            
            # Remove all the useful elements which are now outside the window
            while qu and qu[0] <= i - k:
                qu.popleft()
            
            # Remove all the elements from the right which are smaller than the next element
            while qu and arr[i] >= arr[qu[-1]]:
                qu.pop()
            
            qu.append(i)
        
        # Add the greatest from the last window
        ans.append(arr[qu[0]])
        return ans