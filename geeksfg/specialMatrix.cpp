#include "custHead.h"
using namespace std;

int mod = 1e9 + 7;

string pairString(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }

int FindWays1(int n, int m, vector<vector<int>>blocked_cells){
	   map<pair<int, int>, bool> mp;
	   vector<vector<int>> dp(n, vector<int>(m, 0));
	   for(auto i: blocked_cells) mp[{i[0]-1, i[1]-1}]=1;
	   for(int i=0; i<n; i++){
	       for(int j=0; j<m; j++){
	           if(mp[{i, j}]==1) {
	               dp[i][j]=0;
	           }
	           else if(i==0 && j==0){
	               dp[i][j]=1;
	           }
	           else{
	               if(i>0) dp[i][j] += dp[i-1][j];
	               if(j>0) dp[i][j] += dp[i][j-1];
	           }
	       }
	   }
       for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
               cout << dp[i][j] << ' ';
           }
           cout << '\n';
       }
	   return dp[n-1][m-1]%mod;

	}

    int FindWays2(int n, int m, vector<vector<int>>blocked_cells){
	    
	    vector<vector<int> > tab (n, vector<int> (m, 0));
	    unordered_set<string> blocked;
	    for (int i = 0; i < blocked_cells.size(); i++) {
	        blocked.insert(pairString(blocked_cells[i][0]-1, blocked_cells[i][1]-1));
	    }
	    if (blocked.find("00") != blocked.end()) 
	        return 0;
	    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (blocked.find(pairString(i, j)) != blocked.end()) {
                    tab[i][j] = 0;
                }
                else if (i == 0 && j == 0) {
                    tab[i][j] = 1;
                }
                else {
                    if (i > 0) tab[i][j] += tab[i-1][j];
                    if (j > 0) tab[i][j] += tab[i][j-1]; 
                }
                
            }
        }
        for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
               cout << tab[i][j] << ' ';
           }
           cout << '\n';
       }

        return tab[n-1][m-1] % mod;
	}

int main() {
    int n, m, bl;
    cin >> n >> m >> bl;
    vector<vector<int> >blocked_cells(bl, vector<int>(2, 0));
    for (int i = 0; i < bl; i++) {
        int r, c;
        cin >> r >> c;
        blocked_cells[i] = {r, c};
    }
    FindWays1(n, m, blocked_cells);
    cout << "\n\n";
    FindWays2(n, m, blocked_cells);
}