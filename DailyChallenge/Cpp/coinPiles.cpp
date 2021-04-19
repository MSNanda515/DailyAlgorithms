#include <iostream>
using namespace std;

int main(){
    long n;
    cin >> n;
    long a,b;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        long temp;
        temp = min(a,b);
        b = max(a,b);
        a = temp;
        if (a == 2 * b)
            cout << "YES" << endl; 
        else if (b == 2 * a)
            cout << "YES" << endl;
        else{
            long x = b - a;
            if ((a - x)%3==0 && (b-2*x)%3==0 && x <= a)
                cout << "YES" << endl;
            else 
                cout << "NO" << endl;
        }
    }
}