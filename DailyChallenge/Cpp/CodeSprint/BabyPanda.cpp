#include <iostream>

using namespace std;

int main () {
    long long n, m;
    cin >> n >> m;
    int slime = 0;
    if (m < 1) {
        cout << 0 << endl;
        return 0; 
    }
    while (m > 1){
        m = m / 2;
        if ( m % 2 != 0) {
            m--;
            slime++;
        }
    }
    cout << slime << endl;
}