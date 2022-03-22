#include <iostream>
#include <unordered_set>

using namespace std;

class Solution{
  public:
    int palindromeSubStrs(string s) {
        int n = s.size();
        // all values initialized to def false
        bool isPalin[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)   
                isPalin[i][j] = false;
        }
        
        for (int gap = 0; gap < n; gap++) {
            for (int i = 0, j = gap; j < n; j++, i++) {
                if (gap == 0) {
                    isPalin[i][j] = true;
                }
                else if (gap == 1) {
                    if (s[i] == s[j]) {
                        isPalin[i][j] = true;
                    }
                }
                else {
                    // gap is greater than 1, is Palin only if the inner
                    // substr in palin
                    if (s[i] == s[j]) {
                        // start from the next char, and go one less in gap
                        isPalin[i][j] = isPalin[i+1][j-1];
                    }
                    else {
                        isPalin[i][j] = false;
                    }
                }
            }
        }
        unordered_set<string> palinds;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isPalin[i][j]) {
                    palinds.insert(s.substr(i, j-i+1));
                }
            }
        }
        for (auto it : palinds) {
            cout << it << ' ' ;
        }
        return palinds.size();
    }
};

// { Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}
  // } Driver Code Ends