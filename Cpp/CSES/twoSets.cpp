#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    long n;
    cin >> n;
    long temp, acc = 0, i;
    temp = n * (n+1)/2;
    if(temp % 2 != 0){
        // no Solution
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    unordered_set<int> set1;
    temp = temp / 2;
    for (i = 0; temp - acc > n; i++){
        set1.insert(1+i);
        set1.insert(n - i);
        acc += 1 + n;
    }
    if (temp - acc > 0){
        if (temp - acc <= n - i){
            set1.insert(temp - acc);
        }
        else{
            set1.insert(i+1);
            set1.insert(temp - acc - i - 1);
        }
    }
    cout << set1.size() << endl;
    for (int i = n; i >= 1; i--){
        if (set1.find(i) != set1.end())
            cout << i << ' '; 
    }
    cout << '\n' << n - set1.size() << endl;
    for (int i = n; i >= 1; i--){
        if (set1.find(i) == set1.end())
            cout << i << ' ';
    }
    cout << endl;
}
