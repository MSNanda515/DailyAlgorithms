#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int temp = 0, cur;
    long mov = 0;
    cin >> temp;
    cur = temp;
    for (int i = 1;i < n; i++){
        // read input and calculate no of moves
        // cout << cur << ' ';
        cin >> temp;
        if (temp < cur){
            mov += cur - temp; 
        }
        else{
            cur = temp;
        }
    }
    cout << mov << endl;
}