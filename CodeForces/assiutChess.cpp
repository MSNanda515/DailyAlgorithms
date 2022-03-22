#include <iostream>
#include <string>
using namespace std;

int main() {
  int games;
  cin >> games;
  for (int i = 0; i < games; i++) {
    string rep = "";
    int r = 1, c = 1;
    while (rep != "Done") {
      cout << r << ' ' << c << endl;
      r++; c++;
      getline(cin, rep);
    }
  }

}
