#include <iostream>
using namespace std;

int main() {
    int maxScore = 0, maxPos = -1;
    int sum = 0, temp;
    for (int i = 1; i <= 5; i++){
        sum = 0;
        for(int j = 0; j < 4; j++){
            cin >> temp;
            sum += temp;
        }
        if (sum > maxScore)
        {
            maxScore = sum;
            maxPos = i;
        }
    }
    cout << maxPos << ' ' << maxScore << endl;
}
