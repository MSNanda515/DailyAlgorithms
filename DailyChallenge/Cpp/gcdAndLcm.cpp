#include <iostream>
using namespace std;

/*
    Uses the Euclidean algorithm to compute GCD in O(log(min(a,b)) complexity
*/
long gcd(long a, long b){
    if (a == 0)
        // if the smaller no is 0, gcd is the other no
        // by convention
        return b;
    return gcd(b%a, a);
}

int main(){
    long n;
    cin >> n;   // the no of test cases
    long a, b, hcf;
    for (long i = 0; i < n; i++){
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        hcf = gcd(a, b);
        // print the gcd and the lcm
        cout << hcf << ' ' << a/hcf*b << endl;
    }
}