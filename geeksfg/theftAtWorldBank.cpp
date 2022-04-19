#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
    struct col {
        long long w, p;
        long double rat;
        col(long long w, long long p) {
            this->w = w;
            this->p = p;
            this->rat = (long double)(p) / (long double)(w);
        }
    };
    
    static bool comp1(col& c1, col& c2) {
        return c1.rat > c2.rat;
    }
    
	public:
	long double maximumProfit(int N, long long C, vector<long long> w, vector<long long> p){
	    // Code here.
	    vector<col> bank;
	    for (int i = 0; i < N; i++) {
	        bank.push_back(col(w[i], p[i]));
	    }
	    sort(bank.begin(), bank.end(), comp1);
	    long double prof = 0;
	    long long bag = 0;
	    for (int i = 0; i < N; i++) {
	        long long sq =(long long)(sqrt(bank[i].w));
	        if (sq * sq == bank[i].w) {
	            continue;
	        }
	        if (bag + bank[i].w <= C) {
	           // cout << "Added Whole" << bank[i].p << '\n';
	            bag += bank[i].w;
	            prof += bank[i].p;
	        } else {
	            prof += bank[i].rat * (C - bag);
	           // cout << "Added Part" << bank[i].rat * (C - bag) << '\n';
	            break;
	        }
	        
	        if (bag >= C) {
	            break;
	        }
	    }
	   // cout << prof << '\n';
	   // prof = (long double)((long long) (prof * 1000)) / 1000;
	   prof = (long double)((long long)((prof * 1000) + 0.5)) / 1000;
	    return prof;
	}
};


// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		long long C;
		cin >> n >> C;
		vector<long long > w(n), p(n);
		for(int i = 0; i < n; i++){
		    cin >> w[i] >> p[i];
		}
		Solution ob;
		long double ans = ob.maximumProfit(n, C, w, p);
		cout << fixed << setprecision(3) << ans << "\n";
	}  
	return 0;
}