#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int k = 0; k < t; k++) {
        int n;
        cin >> n;
        if (n < 7){
            cout << -1 << endl;
            continue;
        }
        if (n > 100) {
            n = n % 10;
            switch (n){
                case 1: cout << 3;
                    break;
                case 2: cout << 6;
                    break;
                case 3: cout << 9;
                    break;
                case 4: cout << 2;
                    break;
                case 5: cout << 5;
                    break;
                case 6: cout << 8;
                    break;
                case 7: cout << 1;
                    break;
                case 8: cout << 4;
                    break;
                case 9: cout << 7;
                    break;
                case 0: cout << 10;
                    break;
            }
            cout << endl;
            continue;
        }
        else {
            switch (n%10){
                case 1: 
                    if (n < 21) {
                        cout << -1;
                        break;
                    }
                    cout << 3;
                    break;
                case 2: 
                    if (n < 42){
                        cout << -1 ;
                        break;
                    }
                    cout << 6;
                    break;
                case 3: 
                    if (n < 63){
                        cout << -1 ;
                        break;
                    }
                    cout << 9;
                    break;
                case 4: 
                    if (n < 14){
                        cout << -1 ;
                        break;
                    }
                    cout << 2;
                    break;
                case 5: 
                    if (n < 35){
                        cout << -1 ;
                        break;
                    }
                    cout << 5;
                    break;
                case 6: 
                    if (n < 56){
                        cout << -1 ;
                        break;
                    }
                    cout << 8;
                    break;
                case 7: 
                    if (n < 7){
                        cout << -1 ;
                        break;
                    }
                    cout << 1;
                    break;
                case 8: 
                    if (n < 28){
                        cout << -1 ;
                        break;
                    }
                    cout << 4;
                    break;
                case 9: 
                    if (n < 49){
                        cout << -1 ;
                        break;
                    }
                    cout << 7;
                    break;
                case 0: 
                    if (n < 70){
                        cout << -1 ;
                        break;
                    }
                    cout << 10;
                    break;
            }
            cout << endl;
        }
    }
}