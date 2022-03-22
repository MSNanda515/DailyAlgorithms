#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int ar[n];
    for (int i = 0; i < n; i++){
        ar[i] = 0;
    }
    int temp;
    for (int i = 0; i < n-1; i++){
        cin >> temp;
        ar[temp-1] = 1;
    }
    for (int i = 0; i < n; i++){
        if (ar[i] == 0){
            cout << i+1 << endl;
            break;
        }
    }
}