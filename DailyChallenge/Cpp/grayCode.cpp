// https://cses.fi/problemset/task/2205/
#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;

void dumpBits(int n, int k){
    int temp = pow(2,n-1);
    for(int i = 0; i < n; i++){
        if(temp <= k){
            cout<<1;
            k = k - temp;
        }
        else
            cout << 0;
        temp /= 2;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    vector<int> ser;
    // define the pattern
    // bottom-up approach
    ser.push_back(0);
    ser.push_back(1);
    dumpBits(n, 0);
    dumpBits(n, 1);
    int cur = 2;
    int lim = pow(2, n-1);
    for(; cur <= lim; cur*=2){
        int temp = ser.size();
        for (int j = temp - 1; j>=0; j--){
            ser.push_back(cur+ser[j]);
            dumpBits(n, cur+ser[j]);
        }
    }
}