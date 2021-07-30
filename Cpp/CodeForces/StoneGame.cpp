#include <iostream>

using  namespace std;

int main() {
  int t;
  cin >> t;
  int maxPower, minPower, maxPos, minPos;
  int temp;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    maxPower = 0;
    minPower = n + 1;
    for (int j = 0; j < n; j++) {
      cin >> temp;
      if (temp > maxPower){
        maxPower = temp;
        maxPos = j;
      }
      if (temp < minPower) {
        minPower = temp;
        minPos = j;
      }
    }
    if (maxPos < minPos) {
      temp = maxPos;
      maxPos = minPos;
      minPos = temp;
    } 
    int ar[] = {
      minPos + 1 + n - maxPos,
      maxPos + 1,
      n - minPos
    };
    int minMove = n + 1;
    for (int j = 0; j < 3; j++) {
      if (minMove > ar[j]){
        minMove = ar[j];
      }
    }
    cout << minMove << endl;
  }
}