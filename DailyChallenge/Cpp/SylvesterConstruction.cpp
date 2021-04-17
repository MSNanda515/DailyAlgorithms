#include <iostream>
#include "../Weekly/matrix/matrix.h"

int main(){
    float *ar = new float[1];
    ar[0] = 1; 
    int d;
    int t = 2;
    // Matrix a = Matrix(1,1, ar);
    // cout << a;
    while(1){
        cin >> d;
        d = 1;
        float * ar1 = new float[t*t];
        for (int i = 0; i < 4; i++){
            if (i == 3)
                d = -1;
            for (int j = 0; j < (t/2)*(t/2); j++){       
                ar1[i*t/2 + j] = ar[j]*d;
            }
        }
        delete[] ar;
        ar = ar1;
        Matrix a = Matrix(t, t, ar);
        
        
        cout << a;
        cout << endl;
        t = t*2;
    }
}