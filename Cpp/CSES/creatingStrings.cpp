#include <iostream>
#include <string>
#include <unordered_set>
// find all the permutations of the string given
// I am going to try out the DP approach
using namespace std;

void permutations(string& fix, string& shuffle) {
  // cout << "***" << fix << "  " << shuffle << "***\n";
  // Base Case
  if (shuffle.size() == 1) {
    cout << fix << shuffle << '\n';
  }
  for (int i = 0; i < shuffle.size(); i++) {
    string tempFix = fix + shuffle[i];
    string tempShuffle = shuffle;
    tempShuffle.erase(i, 1);
    permutations(tempFix, tempShuffle);
  }
}

int main() {
  string str;
  getline(cin, str);
  int fact = 1;
  unordered_set<char> repCharSet;
  int repChar = 1 ;
  for (int i = 0; i < str.size(); i++) {
    fact *= (i+1);
    if (repCharSet.find(str[i]) == repCharSet.end()) {
      repCharSet.insert(str[i]);
      // cout << str[i] << " not found" << '\n';
    }
    else {
      repChar++;
      // cout << str[i] << "Found" <<endl;
    }
  }
  // cout << "***" << fact << " "  << repChar << '\n';
  for (int i = 2; i <= repChar; i++)
    fact /= i;
  cout << fact << "\n";
  // string fixed = "";
  // permutations(fixed, str);
  return 0;
}