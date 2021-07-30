#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// struct heapItem{
//     int a;
//     long b;
// };

// bool operator>(heapItem lhs, heapItem rhs){
//     return lhs.b > rhs.b;
// }
// bool operator<(heapItem lhs, heapItem rhs){
//     return lhs.b < rhs.b;
// }

struct drop{
    int id, x, y;
};
struct sen{
    int id, x1, x2, y;
    // int hash(){
    //     return id;
    // }
};

bool operator<(const drop& lhs, const drop& rhs){
    return lhs.y < rhs.y;
}

bool operator>(const drop& lhs, const drop& rhs){
    return lhs.y > rhs.y;
}


bool operator>(const sen& lhs, const sen& rhs){
    return lhs.y > rhs.y;
}

bool operator<(const sen& lhs, const sen& rhs){
    return lhs.y < rhs.y;
}



int main(){
    // heapItem mm[] = {{1,1}, {2, 2}, {3,3}};
    // priority_queue<heapItem, vector<heapItem>, less<heapItem> > ff(mm, mm+3);
    // cout << ff.top().b << endl;
    int d, s;
    cin >> d >> s;
    drop *dr = new drop[d];
    unordered_map<int, priority_queue<drop, vector<drop>, greater<drop> > > eve;
    priority_queue<sen, vector<sen>, less<sen> > se;
    unordered_set<int> explDr;
    int *ans = new int[d];
    for (int i = 0; i < d; i++)
        ans[i] = 0;
    int x1, x2, y;
    drop tempDr;
    for (int i = 0; i < d; i++){
        // get the coordinates of the drop
        cin >> x1 >> y;
        tempDr.id = i; tempDr.x = x1; tempDr.y = y;
        dr[i] = tempDr;
    } 
    sen tempSr;
    for(int i = 0; i < s; i++){
        cin >> x1 >> x2 >> y;
        tempSr.id = i; tempSr.x1 = x1; tempSr.x2 = x2; tempSr.y = y;
        se.push(tempSr);
        eve[i];
        for (int j = 0; j < d; j++){
            if (dr[j].x >= x1 && dr[j].x <= x2 && dr[j].y > y){
                // lies on top of sensor
                eve[i].push(dr[j]);
            }
        }
    }
    delete[] dr;
    int f1 = 0;
    drop temp2;
    while(eve.size() > 0){
        tempSr = se.top();
        se.pop();
        if (eve[tempSr.id].size() == 0){
            eve.erase(tempSr.id);
            continue;
        }
        tempDr = eve[tempSr.id].top();
        while(explDr.find(tempDr.id) != explDr.end()){
            eve[tempSr.id].pop();
            if (eve[tempDr.id].size() <= 0){
                eve.erase(tempSr.id);
                f1 = 1;
                break;
            }
            tempDr = eve[tempSr.id].top();
        }
        if(f1 == 1){
            f1 = 0;
            continue;
        }
        explDr.insert(tempDr.id);
        ans[tempDr.id] = tempSr.y;
        while(true){
            // cout << "11 " << tempSr.id << endl;
            if (eve[tempSr.id].size() == 0)
                break;
            temp2 = eve[tempSr.id].top();
            if (temp2.y == tempDr.y){
                if (explDr.find(temp2.id) == explDr.end()){
                    ans[temp2.id] = tempSr.y;
                    explDr.insert(temp2.id);
                }
                eve[tempSr.id].pop();
            }
            else
                break;
        }
        eve.erase(tempSr.id);
    }
    for (int i = 0; i < d; i++){
        cout << ans[i] << endl;
    }
    delete[] ans;
}