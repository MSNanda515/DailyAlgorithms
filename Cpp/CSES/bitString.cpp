#include <iostream>
#include <cmath>

using namespace std;

int main(){
    long n, mod, quo, rem;
    mod = pow(10, 9) + 7;
    quo = 0;
    rem = 1;
    cin >> n;
    for (long i = 1; i <= n; i++){
        quo *= 2;
        rem *= 2;
        // check if any carry from rem
        if (rem >= mod){
            quo++;
            rem -= mod;
        }
    }
    cout << rem << endl;
}