#include <iostream>
#include <vector>

using namespace std;

vector<long long> deter_dig() {
    long long  dig = 0;
    vector<long long> bound;
    bound.push_back(0);
    long long  temp = 1;
    for (int i = 1; i <= 17; i++) {
        dig += 9 * temp * i;
        bound.push_back(dig);
        temp *= 10;
    }
    return bound;
}

/**
     * Returns the lower bound of position, aka the no of digits
*/
int deter_pos(const vector<long long>& bound, const long long& pos) {
//    int lb = 0;
//    int n = bound.size() - 1;
//    int ub = n;
//    while (lb <= ub) {
//        int mid = (lb + ub) / 2;
//        if (bound[mid] < pos && mid <= n && bound[mid+1] > pos)
//            return mid;
//        else if (bound[mid] < pos) {
//            lb = mid;
//        }
//        else
//            ub = mid - 1;
//    }
    for (int i = 0; i < bound.size()-1; i++) {
        if (bound[i] < pos && bound[i + 1] >= pos) {
            return i;
        }
    }
    return -1;
}


char deter_dig(long pos, int dig, const vector<long long>& bound) {
    long jump = (pos - bound[dig]-1) / (dig + 1);
    long crawl = (pos - bound[dig]-1) % (dig + 1);
    long bb = 1;
    for (int i = 1; i < (dig + 1); i++)
        bb *= 10;
    long no = bb + jump;
    string strNo = to_string(no);
    return strNo[crawl];
}


int main() {
    vector<long long>bound = deter_dig();
    int n;
    long pos;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> pos;
        int dig = deter_pos(bound, pos);
        cout << deter_dig(pos, dig, bound) << '\n';
    }
}