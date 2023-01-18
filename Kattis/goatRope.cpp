#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using namespace std;

struct Point {
    int x, y;
};

double findDist(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void sol(int x, int y, int x1, int y1, int x2, int y2) {
    Point p1, p2, p3, p4;
    if (x1 < x2) {
        if (y1 < y2) {
            // cout << "1";
            p1.x = x1; p1.y = y1;
            p3.x = x2; p3.y = y2;
            p2.x = x1; p2.y = y2;
            p4.x = x2; p4.y = y1;
        } else {
            // cout << "2";
            p2.x = x1; p2.y = y1;
            p4.x = x2; p4.y = y2; 
            p1.x = x1; p1.y = y2;
            p3.x = x2; p3.y = y1; 
        }
    } else {
        if (y1 < y2) {
            // cout << "3";
            p4.x = x1; p4.y = y1;
            p2.x = x2; p2.y = y2;
            p1.x = x2; p1.y = y1;
            p3.x = x1; p3.y = y2;
        } else {
            // cout << "4";
            p3.x = x1; p3.y = y1;
            p1.x = x2; p1.y = y2; 
            p2.x = x2; p2.y = y1;
            p4.x = x1; p4.y = y2; 
        }
    }
    // cout << endl;
    // cout << "p1: " << p1.x << " " << p1.y << endl; 
    // cout << "p2: " << p2.x << " " << p2.y << endl;
    // cout << "p3: " << p3.x << " " << p3.y << endl;
    // cout << "p4: " << p4.x << " " << p4.y << endl;

    if (x >= p1.x && x <= p4.x) {
        // cout << "1" << endl;
        cout << double(abs(min(y-p1.y, x-p2.y))) << '\n';
    } else if (y >= p1.y && y <= p2.y) {
        // cout << "2" << endl;
        cout << double(abs(min(x-p1.x, x-p4.x))) << '\n';
    } else {
        // cout << "3" << endl;
        Point p;
        p.x = x; p.y = y;
        cout << min(findDist(p, p1), min(findDist(p, p2), min(findDist(p, p3), findDist(p, p4)))) << '\n';
    }
}

int main() {
    int x, y, x1, y1, x2, y2;
    cin >> x >> y >> x1 >> y1 >> x2 >> y2;
    // cout << x1 << " " << y1 << " " << x2 << " " << y2 << endl; 
    sol(x, y, x1, y1, x2, y2);
}