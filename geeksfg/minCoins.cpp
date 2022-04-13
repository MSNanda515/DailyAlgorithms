
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

class Solution{
	public:
	int MinCoin(vector<int>nums, int amount)
	{
	    vector<int> dp(amount+1, INT_MAX);
	    dp[0] = 0;
	    for (int i = 1; i <= amount; i++) {
	        for (int j = 0; j < nums.size(); j++) {
	            if (nums[j] <= i &&  dp[i - nums[j]] != INT_MAX) {
	                dp[i] = min(dp[i], dp[i - nums[j]] + 1);
	            }
	        }
	    }
	    
	   if (dp[amount] == INT_MAX)
	        return -1;
	   return dp[amount];
	    
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, amount;
		cin >> n >> amount;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.MinCoin(nums, amount);
		cout << ans <<"\n";
	}
	return 0;
}