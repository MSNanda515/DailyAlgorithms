#include <iostream>
#include <vector>
#include <algorithm>

using  namespace std;

int main() {
  int t, temp;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> nos;
    for (int j = 0; j < n; j++) {
      cin >> temp;
      nos.push_back(temp);
    }
    sort(nos.begin(), nos.begin()+n);
    int minEl = -1, maxEl = -1, k;
    for (k = 0; k < n -1 ; k++){
      minEl = -1; maxEl = -1;
        for (int j = 1; j < n; j++) {
        if (nos[k] + nos[j] >= l && nos[k] + nos[j] <= r) {
          minEl = j;
          break;
        }
      }
      for (int j = n - 1; j > 0; j--) {
        if (nos[k] + nos[j] > l && nos[k] + nos[j] < r) {
          maxEl = j;
          break;
        }
      }
      if (minEl != -1 && maxEl != -1){
        break;
      }
    }
    
    if (minEl == -1 || maxEl == -1) {
      cout << 0 << endl;
      continue;
    }
    int pairs;
    if (minEl <= k){
      pairs = maxEl - minEl;
    }
    else 
      pairs = maxEl - minEl + 1;
    // cout << "**" << minEl << " " << maxEl << endl;
    for (int j = k + 1; j < maxEl; j++) {
      while (minEl - 1 >= 0 && nos[j] + nos[minEl - 1] >= l && minEl - 1 > j){
        minEl--;
      }
      while (maxEl - 1 >= minEl && nos[j] + nos[maxEl] > r){
        maxEl--;
      }
      // cout <<"*" << j << " " << minEl << " " << maxEl << " " << pairs << endl;
      if (j == minEl && j <= maxEl)
        minEl++;
      pairs += maxEl - minEl + 1;
    }
    cout << pairs << endl;


    // for (int j = 0; j < n; j++)
    //   cout << nos[j] << " " ;
  }
}