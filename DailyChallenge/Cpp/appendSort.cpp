#include <iostream>

using namespace std;

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++){
        int n;
        cin >> n;
        int temp;
        cin >> temp;
        int cur = temp, app = 0;
        // cout << "Cur = " << cur << endl;
        for (int j = 1; j < n; j++){
            cin >> temp;
            while (true){
                // cout << "Cur = " << cur << endl;       
                if (temp > cur){
                    cur = temp;
                    break;
                }
                if (temp*10 > cur){
                    cur = temp * 10;
                    app++;
                    break;
                }
                // cout << "Cur = " << cur << endl;       
                if (temp*10+(cur%10)+1 > cur && (cur%10)!=9){
                    cur = temp*10+(cur%10)+1;
                    app++;
                    break;
                }
                if ((temp*10)+9 > cur){
                    cur = temp * 10 + 9;
                    app ++;
                    break;
                }
                // cout << "Cur = " << cur << endl;       
                app++;
                temp = temp*10;
            }
        }       
        cout << "Case #" << i+1 << ": " << app << endl; 
    }
    return 0;
}