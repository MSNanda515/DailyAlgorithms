#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n; 
    unsigned int speed, t, dist;
    vector<unsigned int> speeds;
    vector<unsigned int> time;
    for (int i = 0; i <= 10; i++){
        cin >> n;
        if (n == -1)
            break;
        speeds.clear();
        time.clear();
        for (int j = 0; j < n; j++){
            cin >> speed;
            cin >> t;
            speeds.push_back(speed);
            time.push_back(t);
        }
        dist = 0;
        int prev = 0; 
        for (int j = 0; j < n; j++){
            dist += speeds[j] * (time[j] - prev);
            prev = time[j];
        }
        cout << dist << " miles" << endl;
    }
   
    
}