#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct road{
    long ref;
    long dest;
    long bridge;
};
ostream& operator<<(ostream& out, const road& rhs){
    out << rhs.ref << " - " << rhs.dest << " : " << rhs.bridge << endl;
    return out;
}

ostream& operator<<(ostream& out, const vector<road>& rhs){
    for (auto it = rhs.begin(); it != rhs.end(); it++)
        out << *it;
    return out;
}

ostream& operator<<(ostream& out, unordered_map<long, char>& rhs){
    for (auto it = rhs.begin(); it != rhs.end(); it++)
        out << it->first << "->";
    cout << "...";
    return out;
}

long explore(unordered_map<long, vector<road> >& paths, long br, long pos, const long n, unordered_map<long, char> route){
    // define base case
    if (pos == n)
        return br;
    // if a closed loop has been encountered
    if (br >= n)
        return br;
    long tempBr = n + 1;
    long temp;
    for (road x: paths[pos]){
        // cout << "Been Here";
        if (route.find(x.dest) == route.end()){
            route[x.dest] = '0'; 
            temp = explore(paths, br + x.bridge, x.dest, n, route);
            // cout << "Called " << route << temp << endl;
            if (tempBr > temp)
                tempBr = temp;
        }
    }
    br = tempBr;
    return br;
}

int main(){
    long n, m;
    unordered_map<long, vector<road> > paths;
    for (long i = 0; i < n; i++){
        vector<road> temp;
        paths[i+1] = temp;
    }
    cin >> n >> m;
    long a, b, c;
    for (long i = 0; i < m; i++){
        cin >> a >> b >> c;
        road tempRoad1 = {a,b,c};
        road tempRoad2 = {b,a,c};
        paths[a].push_back(tempRoad1);
        paths[b].push_back(tempRoad2);
    }
    // for (long i = 0; i < n; i ++){
    //     cout << paths[i+1];
    // }
    unordered_map<long, char> route;
    cout << explore(paths, 0, 1, n, route) << endl;
    
}