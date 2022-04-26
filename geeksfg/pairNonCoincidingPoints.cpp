#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int numOfPairs(int X[], int Y[], int N) {
        // code here
        unordered_map<int, int> xp, yp;
        for (int i = 0; i < N; i++) {
            xp[X[i]];
            xp[X[i]]++;
            yp[Y[i]];
            yp[Y[i]]++;
        }
        int pairs = 0;
        for (auto it=xp.begin(); it != xp.end(); it++) {
            if (it->second > 1) {
                pairs += it->second * (it->second - 1) / 2;
            }
        }
        for (auto it=yp.begin(); it != yp.end(); it++) {
            if (it->second > 1) {
                pairs += it->second * (it->second - 1) / 2;
            }
        }
        unordered_map<string, int> id;
        for (int i = 0; i < N; i++) {
            string p = to_string(X[i]) + "," + to_string(Y[i]);
            id[p]++;
        }
        int dup = 0;
        for (auto it = id.begin(); it != id.end(); it++) {
            if (it->second > 1) {
                dup += it->second - 1;
            }
        }
        return pairs - 2*dup;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        int X[N], Y[N];
        
        for(int i=0; i<N; i++)
            cin>>X[i];
        for(int i=0; i<N; i++)
            cin>>Y[i];

        Solution ob;
        cout << ob.numOfPairs(X,Y,N) << endl;
    }
    return 0;
}