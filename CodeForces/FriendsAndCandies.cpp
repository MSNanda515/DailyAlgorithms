#include <iostream>

using  namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int sumCandy = 0;
    int candies[n];
    for (int j = 0; j < n; j++) {
      cin >> candies[j];
      sumCandy += candies[j];
    }
    if (sumCandy % n != 0) {
      cout << -1 << endl;
      continue;
    }
    int eachShare = sumCandy / n;
    int k = 0;
    for (int j = 0; j < n; j++) {
      if (candies[j] > eachShare)
        k++;
    }
    cout << k << endl;
  }
}