// https://practice.geeksforgeeks.org/problems/subsets-with-xor-value2023/1#

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
    /**
     * dp[i][j] keeps track of the subarrays till i-1 who have xor value of k
     * */
    int solveDp(vector<int>& arr, int n, int k, vector<vector<int>>& dp) {
        if (n == 0) {
            // no array, so not possible to have subarray with xor of k   
            return 0;
        }
        if (dp[n][k] != -1) {
            return dp[n][k];
        }

        // k = k^arr[n-1], since when arr[n-1] xored both sides in the subarray smaller than n
        // will recover k
        int considerN = solveDp(arr, n-1, k^arr[n-1], dp);
        int leaveN = solveDp(arr, n-1, k, dp);
        dp[n][k] = considerN + leaveN;
        return dp[n][k];
    }

public:
    
    int subsetXOR(vector<int> arr, int N, int K) {
        // 128 chosen because arr[i] < 100, and the maximum xor possible with the no of 
        // bits is pow(2, log2(100) + 1) - 1 = 127
        vector<vector<int>> dp(N+1, vector<int> (128,-1));
        
        return solveDp(arr, N, K, dp);
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        int K;
        cin>>K;
        vector<int> v;
        for(int i = 0;i<N;i++)
        {
            int x;
            cin>>x;
            v.push_back(x);
        }    
        Solution ob;
        cout << ob.subsetXOR(v,N,K) << endl;
    }
    return 0; 
}