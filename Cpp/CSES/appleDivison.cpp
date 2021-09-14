#include <iostream>
#include <vector>
using namespace std;

class Sol {
  vector<unsigned int> nos, bag1, bag2;
  long long sum1, sum2, minDiff;


public:  

  Sol(vector<unsigned int>& nos, long long minDiff) {
    this->nos = nos;
    this->minDiff = minDiff;
  }

  void distributeBag(int index) {
    // Define the base case
    if (index == nos.size() - 1) {
      // The last index
      long long absDiff = abs(sum1 - sum2);
      if (absDiff < minDiff) {
        minDiff = absDiff;
        return;
      }
    }
    // Divide the no at index to the two bags
    addNumberBag(bag1, sum1, index);
    distributeBag(index + 1);
    removeNumberBag(bag1, sum1, index);
    addNumberBag(bag2, sum2, index);
    distributeBag(index + 1);
    removeNumberBag(bag2, sum2, index);
  }

  void addNumberBag(vector<unsigned int>& b, long long & runSum, int i) {
    b.push_back(nos[i]);
    runSum += nos[i];
  }
  void removeNumberBag(vector<unsigned int>& b, long long & runSum, int i) {
    b.pop_back();
    runSum -= nos[i];
  }

  long long leastDiff() {
    distributeBag(0);
    return minDiff;
  }
};

int main() {
  // Get all the data
  int n;
  cin >> n;
  vector<unsigned int> nos;
  long long minDiff = 0;
  for (int i = 0; i < n; i++) {
    // get the inputs for the array
    int temp;
    cin >> temp;
    minDiff += temp;
    nos.push_back(temp);
  }
  Sol* solution = new Sol(nos, minDiff);
  cout << solution->leastDiff() << endl;
}