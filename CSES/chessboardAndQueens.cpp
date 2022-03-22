#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int N = 0;

bool check_if_valid_to_place(const vector<unordered_set<int> >& occ, const int& row, const int& col) {
    bool colCheck = occ[0].find(col) == occ[0].end();
    bool diag1Check = occ[1].find(row+col) == occ[1].end();
    bool diag2Check = occ[2].find(row-col+7) == occ[2].end();
    return colCheck && diag1Check && diag2Check;
}


void place_queen_cell(vector<unordered_set<int> >& occ, const int& row, const int& col) {
    occ[0].insert(col);
    occ[1].insert(row+col);
    occ[2].insert(row-col+7);
}

void remove_queen_cell(vector<unordered_set<int> >& occ, const int& row, const int& col) {
    occ[0].erase(col);
    occ[1].erase(row+col);
    occ[2].erase(row-col+7);
}


void place_queen(vector<unordered_set<int> >& occ, int row, const vector<unordered_set<int> >& res) {
    if (row == 8) {
        // The row is at the last position, one possible solution found
        N++;
        return;
    }
    // Check all the possible solutions using backtracking
    for (int i = 0; i < 8; i++) {
        // Check if we can place queen at this position
        if (res[row].find(i) != res[row].end())
            continue;
        if (!check_if_valid_to_place(occ, row, i))
            continue;
        // Valid to place queen in this cell
        place_queen_cell(occ, row, i);
        // Place queen in next cell
        place_queen(occ, row+1, res);
        // Explore diff sols
        remove_queen_cell(occ, row, i);
    }
}


void place_queen() {
    vector<unordered_set<int> > res;
    char temp;
    for (int i = 0; i < 8; i++) {
        unordered_set<int> rowRes;
        res.push_back(rowRes);
        for (int j = 0; j < 8; j++) {
            cin >> temp;
            if (temp == '*') {
                res[i].insert(j);
            }
        }
    }
    vector<unordered_set<int> > occ;
    for (int i = 0; i < 3; i++) {
        unordered_set<int> occSet;
        occ.push_back(occSet);
    }
    place_queen(occ, 0, res);
}

int main() {
    place_queen();
    cout << N << endl;
}