// https://cses.fi/problemset/task/1629/
// Used Greedy Algorithm while sorting the movies according to the movie which ends earliest

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

bool compMovies(vector<int>& m1, vector<int>& m2) {
    return m1[1] < m2[1];
}

int sol(vector<vector<int>>& movies) {
    sort(movies.begin(), movies.end(), compMovies);
    int watch = 0, cur = 0;
    for (int i = 0; i < movies.size(); i++) {
        if (movies[i][0] >= cur) {
            watch++;
            cur = movies[i][1];
        }
    }
    return watch;
}

int main(){
	int n;
    cin >> n;
    vector<vector<int>> movies;
    for (int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        movies.push_back({start, end});
    }
    cout << sol(movies) << endl;
}