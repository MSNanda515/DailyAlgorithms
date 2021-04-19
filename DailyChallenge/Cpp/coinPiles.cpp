#include <iostream>
using namespace std;

int main(){
    long n;
    cin >> n;
    long a,b;
    for (int i = 0; i < n; i++){
        cin >> a >> b;
        if (a == 2 * b)
            cout << "YES" << endl;
        // else if (a == 0 || b == 0)
        //     cout << "YES" << endl; 
        else if (b == 2 * a)
            cout << "YES" << endl;
        else if (a%3 == 0 && b%3==0 && a!=0 && b!=0)
            cout << "YES" << endl;
        else if (((a%3 == 1 && b%3 == 2) || (a%3==2 && b%3==1)) && abs(a-b)<min(a,b))
            cout << "YES" << endl;
        else    
            cout << "NO" << endl;
    }
}