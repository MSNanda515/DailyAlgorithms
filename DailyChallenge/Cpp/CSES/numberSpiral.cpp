#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    long x, y;
    for (int i = 0; i < t; i++){
        cin >> y >> x;
        y--;
        x--;
        if (y > x){
            // lower Triangle
            if (y % 2 == 0){
                cout << (y*y + x + 1) << endl;
            }
            else{
                cout << (y*y +y + 1 + y - x) << endl;
            }
        }
        else{
            // upper triangle
            if (x % 2 == 0){
                cout << (x*x + x + 1 + x - y) << endl;
            }
            else{
                cout << (x*x + y + 1) << endl;
            }
        }
    }
}