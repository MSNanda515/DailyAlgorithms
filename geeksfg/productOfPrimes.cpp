#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution{
    bool isPrime(long long no) {
        for (long long i = 2; i * i <= no; i++) {
            if (no % i == 0) {
                return false;
            }
        }
        return true;
    }
    
public:
    long long primeProduct(long long L, long long R){
        // code here
        long long mod = 1e9 + 7;
        long long prod = 1;
        for (long long i = L; i <= R; i++) {
            if (isPrime(i)) {
                prod = (prod * i) % mod;
            }
        }
        return prod;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;
        
        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}