#include <iostream>

using namespace std;

int main() {
    int t;
    long long a, b, d, day, night, total; 
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> total >> night;
        cin >> a >> b >> d;
        b = b - a;
        day = total - night;
        long long temp = (a + 2 * b + d);
        if (temp < day) {
            cout << "YES" << endl;
        }
        else if (temp % total == 0 && temp < day * temp / total) {
            cout << "YES" << endl;
        }
        else if (temp % total < day && temp > total){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
