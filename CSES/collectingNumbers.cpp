// https://cses.fi/problemset/result/3925593/
// Time Complexity: O(n), Space Complexity: O(n)
// divides the numbers into bag, based on the observation
// that we can only collect n if n-1 is collected in the run

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main(){
    int n, temp;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        nums[i] = temp;
    }

    // keep track of the run when item is collected
    vector<int> bag(n+1, -1);
    bag[0] = 1;
    int k = 1, dig;
    for (int i = 0; i < n; i++) {
        dig = nums[i];
        if (bag[dig-1] == -1)  {
            // previous item not collected, start a new run
            k++;
            bag[dig] = k;
        } else {
            // dig collected in the same run as dig - 1
            bag[dig] = bag[dig-1];
        }
    }
    cout << k << endl;
}