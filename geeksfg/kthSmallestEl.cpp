// https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Solved using the quick select algorithm
// Time complexity: O(n)
// Space complexity: O(log(n))
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
    void swapEl(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }
    
    int partition(int arr[], int lo, int hi) {
        int randInd = rand()%(hi-lo + 1) + lo;
        swapEl(arr[hi], arr[randInd]);
        int pivotInd = lo;
        int pivotVal = arr[hi];
        for (int i = lo; i < hi; i++) {
            if (arr[i] < pivotVal) {
                swapEl(arr[i], arr[pivotInd]);
                pivotInd++;
            }
        }
        swapEl(arr[pivotInd], arr[hi]);
        return pivotInd;
    }
    
    int quickSelect(int arr[], int l, int r, int k) {
        if (l <= r) {
           int pivotInd = partition(arr, l, r);
           if (pivotInd == k) {
               return arr[k];
           } else if (pivotInd > k) {
               return quickSelect(arr, l, pivotInd-1, k);
           } else {
               return quickSelect(arr, pivotInd+1, r, k);
           }
       }
       return arr[l];
    }
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //code here
       return quickSelect(arr, l, r, k-1);
    }
};

// { Driver Code Starts.
 
int main()
{
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        Solution ob;
        cout<<ob.kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}  // } Driver Code Ends