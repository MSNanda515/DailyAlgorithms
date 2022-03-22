#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long findRank(string str) {
        long long fact[26];
        fact[0] = 1;
        for (int i = 1; i < 26; i++) {
            fact[i] = fact[i-1] * i;
        }
        
        long long ans = 0;
        int n = str.size();
        for (int i = 0; i < n-1; i++) {
            int dis = 0;
            for (int j = i + 1; j < n; j++) {
                if (str[i] > str[j])
                    dis++;
            }
            
            ans += fact[n-i-1] * dis;
        }
        return ans + 1;
    }
};

int main(){
    int T;
    cin>>T;
    while(T--){
        string s;
        cin>>s;
        Solution obj;
        long long ans = obj.findRank(s);
        cout<<ans<<endl;
    }
}  