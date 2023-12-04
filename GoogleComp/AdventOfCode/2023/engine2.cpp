#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <format>


using namespace std;

bool isDig(char ch) {
    return ch >= '0' && ch <= '9';
}

bool getDig(int& start, int& end, int& num, int& i, const string& str) {
    start = -1; end = -1;
    for (; i < str.size(); i++) {
        if (start >= 0) {
            if (!isDig(str[i])) {
                end = i - 1;
                num = stoi(str.substr(start, i - start));
                i++;
                return true;
            }
            continue;
        }

        if (isDig(str[i])) {
            // found first dig
            start = i;
        }
    }
    if (start >= 0) {
        end = str.size() - 1;
        num = stoi(str.substr(start));
        return true;
    }
    return false;
}

bool withinBounds(int& row, int& col, vector<string>& grid) {
    return row >= 0 && row < grid.size() && col >= 0 && col < grid[row].size();
}

bool isStar(char ch) {
    return ch == '*';
}

void addGear(unordered_map<string, vector<int>>& gears, int& num, int& starRow, int& starCol) {
    string gearKey =  to_string(starRow) + "," + to_string(starCol);
    gears[gearKey];
    gears[gearKey].push_back(num);
}

bool validPart(const int& row, const int& start, const int& end, vector<string>& grid, unordered_map<string, vector<int>>& gears, int& num) {
    int curRow = row - 1, curCol;
    for (curCol = start - 1, curRow = row - 1; curCol <= end + 1; curCol++) {
        if (!withinBounds(curRow, curCol, grid)) { break; }
        if (isStar(grid[curRow][curCol])) { addGear(gears, num, curRow, curCol); return true; }
    }
    for (curCol = end + 1, curRow = row - 1; curRow <= row + 1; curRow++) {
        if (!withinBounds(curRow, curCol, grid)) { break; }
        if (isStar(grid[curRow][curCol])) { addGear(gears, num, curRow, curCol); return true; }
    }
    for (curCol = end + 1, curRow = row + 1; curCol >= start - 1; curCol--) {
        if (!withinBounds(curRow, curCol, grid)) { break; }
        if (isStar(grid[curRow][curCol])) { addGear(gears, num, curRow, curCol); return true; }
    }
    for (curCol = start - 1, curRow = row + 1; curRow >= row - 1; curRow--) {
        if (!withinBounds(curRow, curCol, grid)) { break; }
        if (isStar(grid[curRow][curCol])) { addGear(gears, num, curRow, curCol); return true; }
    }
    return false;
}

void processGears(unordered_map<string, vector<int> >& gears, long& cum) {
    for (auto it = gears.begin(); it != gears.end(); it++) {
        if (it->second.size() == 2) {
            cum += 1l * it->second[0] * it->second[1];
        }
    }
}


void sol() {
    string input;
    long cum = 0;
    vector<string> grid;
    while (getline(cin, input)) {
        grid.push_back(input);
    }
    
    int row, col, start, end, num;
    bool foundDig = false;
    bool validDig = false;
    unordered_map<string, vector<int>> gears;
    for (int row = 0; row < grid.size(); row++) {
        col = 0;
        while (col < grid[row].size()) {
            foundDig = getDig(start, end, num, col, grid[row]);
            validDig = validPart(row, start, end, grid, gears, num);
        }
    }
    processGears(gears, cum);
    cout << cum << endl;
}

int main() {
    sol();
}