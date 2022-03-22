#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

using namespace std;
string stringFromPair(int i, int j) {
    return to_string(i) + to_string(j);
}

vector<vector<int> > dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool parseTable(int r, int c, const vector<string>& table, unordered_set<string>& ones, unordered_set<string>& rect) {
//    cout << r << ' ' << c << '\n';
    for (int i = 0; i < dir.size(); i++) {
        int nr = r + dir[i][0], nc = c + dir[i][1];
//        cout << nr << ' ' << nc << '\n';
        if (nr < 0 || nr >= table.size() || nc < 0 || nc >= table[0].size()) {
            continue;
        }
        if (table[nr][nc] != '1') {
            continue;
        }
        // its a one
        string coord = stringFromPair(nr, nc);
        if (ones.find(coord) == ones.end()) {
            if (rect.find(coord) == rect.end()) {
                // already seen, but not in the current rect
                return false;
            }
            else {
                // already seen but in the current rect
                continue;
            }
        }

        // not seen before
        // add to current rect, and mark as seen and recurse
        rect.insert(coord);
        ones.erase(coord);
        bool res = parseTable(nr, nc, table, ones, rect);
        if (res == false) {
            return false;
        }
    }
    return true;
}

bool isElegant(const vector<string>& table) {
    unordered_set<string> ones;
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table[i].size(); j++) {
            if (table[i][j] == '1') {
                ones.insert(stringFromPair(i, j));
            }
        }
    }
    while (ones.size() > 0) {
        string o = *(ones.begin());
        int r = 0 + (o[0] - '0');
        int c = 0 + (o[1] - '0');
        unordered_set<string> rect;
        rect.insert(o);
        ones.erase(o);
        bool res = parseTable(r, c, table, ones, rect);
        if (res == false) {
            return false;
        }
    }
    return true;
}


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<string> table;
        for (int i = 0; i < n; i++) {
            string temp;
            cin >> temp;
            table.push_back(temp);
        }
        bool res = isElegant(table);
        if (res)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }
}