#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;


long double findArea(int r) {
    return (long double)(M_PI) * r * r;
}

long double sol(int r, int a, int b) {
    long double area = 0;
    int rad = r;
    int proc = 0;
    while (rad > 0) {
        if (proc % 2 != 0) {
            rad = rad * a;
        } else if (proc != 0) {
            rad = rad / b;
        }
        area += findArea(rad);
        proc++;
    }
    return area;
}


int main() {
    int t;
    cin >> t;
    cout << fixed;
    cout<<setprecision(7);
    for (int i = 0; i < t; i++) {
        int r, a, b;
        cin >> r >> a >> b;
        cout << "Case #" << i+1 << ": " << sol(r, a, b) << '\n';
    }
}