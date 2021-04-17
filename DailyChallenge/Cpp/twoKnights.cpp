#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n;
    cin >> n;
    cout << 0 << endl;
    long temp;
    for (int i = 2; i <= n; i++){
        temp = pow(i, 2) * (pow(i, 2) - 1)/2 - 4*(i - 2)*(i-1);
        cout << temp << endl;
    }
}