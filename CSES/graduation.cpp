#include <iostream>
#include <list>
#include <unordered_set>

using namespace std;

int main(){
    // get the input
    int n, m ,k;
    char classIn;
    cin >> n >> m >> k;
    char group[n][m];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin >> classIn;
            group[i][j] = classIn;
        }       
    }
    // process the input
    int classAss[k];
    for (int i = 0; i < k; i++)
        classAss[i] = -1;

    for (int i = 0; i < m; i++){
        unordered_set<int> groupCol;
        for (int j = 0; j < n; j++){
            groupCol.insert(group[j][i] - 'A');
        }
        int sel = *groupCol.begin();
        // cout << sel << ':';
        unordered_set<int> change;
        for (auto it = groupCol.begin(); it != groupCol.end(); it++){
            change.insert(*it);
            // cout << *it << ' ';
            classAss[*it] = sel;
        }
        // cout << ':';
        for (int j = 0; j < k; j++){
            if (change.find(classAss[j]) != change.end()){
                // cout << j << ' ';
                classAss[j] = sel;
            }
        }
        // cout << endl;
    }
    unordered_set<int> unique;
    int count = 0;
    for (int j = 0; j < k; j++){
        if (unique.find(classAss[j]) == unique.end()){
            count++;
            unique.insert(classAss[j]);
        }
    }
    cout << count << endl;
}