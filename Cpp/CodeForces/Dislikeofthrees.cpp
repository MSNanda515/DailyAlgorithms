#include <iostream>
using namespace std;

int main() {
  int k = 0;
  int el[1000];
  for (int i = 1; k < 1000; i++) {
    if (!(i % 3 == 0 || i % 10 == 3)) {
      // Valid no for the sequence
      el[k++] = i;
    }
  }
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int query;
    cin >> query;
    cout << el[query - 1] << '\n';
  }
}
