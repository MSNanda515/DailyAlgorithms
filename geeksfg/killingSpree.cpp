#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
    long long int sumSquares(long long int k) {
        return (k) * (k+1) * (2*k+1) / 6;
    }
public:
    long long int killinSpree(long long int n)
    {
        // Code Here
        long long int lb = 1, ub = sqrt(n)+1;
        long long int p = n;
        while (lb <= ub) {
            long long int mid = (lb + ub) / 2;
            long long int pReq = sumSquares(mid);
            if (pReq > p) {
                ub = mid - 1;
            } else {
                if (sumSquares(mid+1) <= p) {
                    lb = mid+1;
                } else {
                    return mid;
                }
            }
        }
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int n; cin>>n;
        Solution obj;
        long long int ans = obj.killinSpree(n);
        cout<<ans<<"\n";
    }
    return 0;
}