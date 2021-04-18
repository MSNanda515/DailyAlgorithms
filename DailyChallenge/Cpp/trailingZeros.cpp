/*
    * The no of trailing 0's correspond to min no of 2s and 5s.
        the no of 5s will be less than 2s in n!
    * Finds the no of 5s in the factors of the terms in n! in nlog(n)
        complexity
*/

#include <iostream>
using namespace std;

int main() {
    long n;
    cin >> n;
    int five = 0;
    if (n < 5){
        cout << 0 << endl;
        return 0;
    }
    long j;
    for (long i = 5; i <= n; i += 5){
        j = i;
        while (j % 5 == 0){
            j /= 5;
            five++;
        }
    } 
    cout << five << endl;
} 