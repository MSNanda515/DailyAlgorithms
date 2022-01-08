#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>

#define grid_size 7

using namespace std;

typedef pair<int, int> Point;
typedef vector<pair<Point, int> > PointDir;
int N = 0;
int depth = 0;
int invalidFlag1 = 0;

struct pair_hash {
    inline std::size_t operator()(const std::pair<int,int> & v) const {
        return v.first*31+v.second;
    }
};

typedef unordered_set<Point, pair_hash> VisitedSet;

const int nRow[] = {-1, 0, 1, 0};
const int nCol[] = {0, 1, 0, -1};
const int mDir[] = {0, 1, 2, 3};
// U0 R1 D2 L3

PointDir get_valid_points(const Point& p, const VisitedSet& a) {
    PointDir pointDir;
    int newRow, newCol;
    unordered_set<int> dirAll;
    for (int i = 0; i < 4; i++) {
        newRow = p.first + nRow[i];
        newCol = p.second + nCol[i];
        if (newRow == 0 || newRow == grid_size+1 || newCol == 0 || newCol == grid_size + 1)
            continue;
        Point newPoint (newRow, newCol);
        if (a.find(newPoint) != a.end())
            continue;
        pointDir.push_back(pair<Point, int> (newPoint, mDir[i]));
        dirAll.insert(mDir[i]);
    }
    if ((dirAll.find(0) != dirAll.end() && dirAll.find(2) != dirAll.end())
        && (dirAll.find(1) == dirAll.end() && dirAll.find(3) == dirAll.end())) {
        // Go both up and down but not left or right
        invalidFlag1 = 1;
    }
    if ((dirAll.find(1) != dirAll.end() && dirAll.find(3) != dirAll.end())
        && (dirAll.find(0) == dirAll.end() && dirAll.find(2) == dirAll.end())) {
        // Go both L and R but not U or D
        invalidFlag1 = 1;
    }
    return pointDir;
}


void discoverPath(Point start, const Point& end, vector<int>& path, const vector<int>& temp,
                  VisitedSet& vs) {
//    depth++; cout << depth << ' ';
    int pos = path.size();
    if ((start.first == end.first && start.second == end.second)) {
        if (pos == 48) {
            N++;
        }
        else
            // Prune the branch
            return;
    }
    PointDir pointDir = get_valid_points(start, vs);

    if (invalidFlag1 == 1) {
        invalidFlag1 = 0;
        return;
    }

    if (temp[pos] != 4) {
        // Direction already determined, check if dir in the allowed array
        for (pair<Point, int> it : pointDir) {
            if (it.second == temp[pos]) {
                path.push_back(it.second);
                vs.insert(it.first);
                discoverPath(it.first, end, path, temp, vs);
                path.pop_back();
                vs.erase(it.first);
            }
        }
        return;
    }

    // Explore all the paths
    for (pair<Point, int> it : pointDir) {
        path.push_back(it.second);
        vs.insert(it.first);
        discoverPath(it.first, end, path, temp, vs);
        path.pop_back();
        vs.erase(it.first);
    }
}


int main() {
    vector<int> temp (48);
    string templateStr;
    getline(cin, templateStr);
    for (int i = 0; i < 48; i++) {
        // U0 R1 D2 L3
        int dirInt;
        switch (templateStr[i]) {
            case 'U': dirInt = 0;
                break;
            case 'R': dirInt = 1;
                break;
            case 'D': dirInt = 2;
                break;
            case 'L': dirInt = 3;
                break;
            default: dirInt = 4;
        }
        temp[i] = dirInt;
    }
    vector<int> path;
    VisitedSet vs; vs.insert(Point(1, 1));
    discoverPath(Point(1, 1), Point(grid_size, 1), path, temp, vs);
    cout << N << endl;
//    cout << "depth: " << depth << endl;
}