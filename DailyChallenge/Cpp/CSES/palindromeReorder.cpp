// https://cses.fi/problemset/task/1755/
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
    string seq;
    getline(cin, seq);
    unordered_map<char, int> occ;
    for(int i = 0; i < seq.size(); i++){
        if(occ.find(seq[i]) == occ.end())
            occ[seq[i]] = 1;
        else   
            occ[seq[i]]++;
    }
    char ar[seq.size()+1];
    int c = 0, n = seq.size();
    unordered_set<char> any;
    for(auto it = occ.begin(); it !=occ.end(); it++){
        int k = it->second;
        while(k >= 2){
            ar[c] = it->first;
            ar[n-1-c] = it->first;
            c++;
            k -= 2;  
        }
        if(k==1)
            any.insert(it->first);
    }
    ar[n] = '\0';
    if (c < n/2)
        cout << "NO SOLUTION" << endl;
    else{
        if(any.size() > 0)
            ar[c] = *any.begin();
        cout << ar << endl;
    }
}