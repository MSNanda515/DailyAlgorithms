#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n<=3){
        if (n == 1){
            cout << '1' << endl;
            return 0;
        }
        cout << "NO SOLUTION" << endl;
    }
    else{
        for (int i = 2; i <= n; i += 2){
            cout << i << ' ';
        }
        for (int i = 1; i <= n; i += 2){
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}