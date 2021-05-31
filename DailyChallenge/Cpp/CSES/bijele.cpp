#include <iostream>
using namespace std;

int main(){
    int ar[6] = {1, 1, 2, 2, 2, 8};
    int temp;
    for (int i = 0; i < 6; i++){
        // Get the input 
        cin >> temp;
        // Find the no of piece required
        cout << ar[i] - temp << ' ';
    }
    cout << endl;
}