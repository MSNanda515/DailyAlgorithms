#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
public:	
	vector<int> findPrimes(int n) {
	    vector<int> isPrime(n+1, 1);
	    for (int i = 2; i <= n; i ++) {
	        if (isPrime[i] != 1) {
	            continue;
	        }
	        for (int j = i * 2; j <= n; j += i) {
	            isPrime[j] = 0;
	        }
	    }
	    vector<int> primes;
	    for (int i = 2; i <= n; i++) {
	        if (isPrime[i] == 1) {
	            primes.push_back(i);
	        }
	    }
	    return primes;
	}
	
	bool checkIsSum(vector<int>& primes, int& no) {
	    unordered_set<int> diff;
	    for (int i = 0; i < primes.size(); i++) {
	        diff.insert(primes[i]);
	        if (diff.find(no - primes[i]) != diff.end()) {
	            return true;
	        }
	    }
	    return false;
	}
	
	
	int superPrimes(int n)
	{
	    // Your code goes here
	    vector<int> primes = findPrimes(n);
	    unordered_set<int> primesSet;
	    for (int i = 0; i < primes.size(); i++) {
	        primesSet.insert(primes[i]);
	    }
	    int p = 0;
	    for (int i = 0; i < primes.size(); i++) {
	        if (primesSet.find(primes[i] - 2) != primesSet.end()) {
	            p++;
	        }
	    }
	    return p;
	}
};

// { Driver Code Starts.

int main() 
{

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
   		Solution ob;
   		cout << ob.superPrimes(n) << "\n";
   	}

    return 0;
}