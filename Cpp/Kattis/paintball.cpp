#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iostream>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ", "; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "["; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "{"; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}
template <class T, class V> void _print(map <T, V> v) {cerr << "["; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "["; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "{"; for (T i : v) {_print(i); cerr << " ";} cerr << "}";}



bool findComb(int cur, int& start, unordered_set<int>& left, unordered_map<int, int>& tar, vector<vector<int>>& see, int flag = 0) {
    debug(cur);
    debug(left);
    debug('\n');
    if (cur == start && flag == 0) {
        if (left.size() == 0) {
            return true;
        }
        else  {
            return false;
        }
    }
    for (auto it = see[cur].begin(); it != see[cur].end(); it++) {
        if (left.find(*it) != left.end()) {
            left.erase(*it);
            tar[cur] = *it;
            
            bool found = findComb(*it, start, left, tar, see);
            // cout << cur << ' ' << *it << found << '\n';
            if (found) {
                return true;
            }
            left.insert(*it);
        }
    }
    return false;
}


int sol() {
    int n, m;
    cin >> n >> m;
    if ( m < n) {
        cout << "Impossible" << endl;
        return 0;
    }
    vector<vector<int>> see(n);
    unordered_set<int> left;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        see[a].push_back(b);
        see[b].push_back(a);
        left.insert(a);
        left.insert(b);
    }
    int start = 0;
    unordered_map<int, int> tar;
    bool found = findComb(0, start, left, tar, see, 1);
    if (found) {
        for (int i = 0; i < n; i++) {
            cout << tar[i]+1 << '\n';
        }
    }
    else {
        cout << "Impossible" << '\n';
    }
    return 0;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("Error.txt", "w", stderr);
#endif
    sol();
}
