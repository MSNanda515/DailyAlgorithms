#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long a, b;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        long temp = max(a, b);
        b = min(a, b);
        a = temp;
        if (a == b) {
            if (a % 3 == 0)
                cout << "YES";
            else
                cout << "NO";
        }
        else if (a == 2 * b) {
            cout << "YES";
        }
        else {
            long y = a - b;
            if (b - y < 0 || (b - y)% 3 != 0)
                cout << "NO";
            else
                cout << "YES";
        }
        cout << endl;
    }
}
