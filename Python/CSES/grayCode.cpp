#include <iostream>
#include <cmath>
using namespace std;

int main() {
    string posChar[]= {"0", "1", "1", "0"};
    int n;
    cin >> n;
    int maxEnt = pow(2, n);
    for (int i = 0; i < maxEnt; i++) {
        string ans = "";
        long pp = 1;
        for (int j = 0; j < n; j++, pp*=2) {
            int pos = int(floor(i/pp)) % 4;
            ans = posChar[pos] + ans;
        }
        cout << ans << '\n';
    }
}