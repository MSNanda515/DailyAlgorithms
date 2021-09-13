#include <iostream>
#include <vector>
using namespace std;

class Sol {
  vector<unsigned int> nos, bag1, bag2;
  long long sum1, sum2;

public:  

  Sol(vector<unsigned int>& nos) {
    this.nos = nos;
  }

  long long leastDiff() {
    return nos.size();
  }

};

int main() {
  // Get all the data
  int n;
  cin >> n;
  vector<unsigned int> nos;
  for (int i = 0; i < n; i++) {
    // get the inputs for the array
    int temp;
    cin >> temp;
    nos.push_back(temp);
  }
  Sol solution = new Sol(nos);
  cout << solution.leastDiff();
}