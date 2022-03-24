#include <iostream>
#include <string>

using namespace std;

class Solution{   
    int dpSol(string a, string b, int n) {
        int dp[n+1][n+1];
        
        for (int i = 0; i <= n; i++) {
            dp[0][i] = dp[i][0] = 0;
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return (dp[n][n]);
    }

    int recSol(string& str, int l, int h) {
        if (l > h) return INT_MAX;
        if (l == h) return 0;
        // add a char to if they are diff, otherwise no need
        if (l == h - 1) return (str[l] == str[h]) ? 0 : 1;

        int addChar = 0;
        if (str[l] == str[h]) {
            // ends are same, recurse for other inner strings
            addChar = recSol(str, l+1, h-1);
        }
        else {
            addChar = min(recSol(str, l+1, h), recSol(str, l, h-1)) + 1;
        }
        return addChar;
    }
public:
    int findMinInsertions(string S){
        string a = S;
        reverse(S.begin(), S.end());
        string b = S;
        int left = dpSol(a, b, b.size());
        return b.size() - left;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.findMinInsertions(S)<<endl;
    }
    return 0;
}