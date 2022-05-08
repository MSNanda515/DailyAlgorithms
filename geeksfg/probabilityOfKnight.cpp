// https://practice.geeksforgeeks.org/problems/probability-of-knight5529/1
// Following solution has a time complexity of (N^3)
// Finds the probability of being at each cell in the chess board after each move
// given the initial position
// Deletes the value of the previous position to only account the probabilities at the 
// very last move

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iomanip>

using namespace std;

class Solution{
    // determines if the move is inside board to 
    bool isInsideBoard(int n, int r, int c) {
        if (r >= 0 && r < n && c >= 0 && c < n) {
            return true;
        }
        return false;
    }
	public:
    // finds the prob of a knight being inside the board after
    // k moves
	double findProb(int N,int start_x, int start_y, int steps)
	{
	    // Code here
	    int n = N;
        // stores the current probabilities for being at a cell
	    vector<vector<double>> cur(n, vector<double>(n, 0.0));
        // stores the probabilities of being at a cell in the next move
	    vector<vector<double>> nex(n, vector<double>(n, 0.0));
	    cur[start_x][start_y] = 1;

        // all the valid moves for a knight
	    vector<vector<int>> dir = {
            {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
	        {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
	    };

	    for (int k = 0; k < steps; k++) {
	        for (int i = 0; i < n; i++) {
	            for (int j = 0; j < n; j++) {
	                int nextR, nextC;
                    // If knight ever visits this cell
	                if (cur[i][j] != 0) {
	                    for (int d = 0; d < 8; d++) {
    	                    nextR = i + dir[d][0];
    	                    nextC = j + dir[d][1];
    	                    if (isInsideBoard(n, nextR, nextC)) {
                                // if it is a valid move, calculate the probability of being
                                // at the cell
    	                        nex[nextR][nextC] += cur[i][j] / 8;
    	                    }
    	                }
	                }
	                cur[i][j] = 0;
	            }
	        }

            // prepare the record for the next move
	        for (int i = 0; i < n; i++) {
	            for (int j = 0; j < n; j++) {
	                cur[i][j] = nex[i][j];
	                nex[i][j] = 0;
	            }
	        }
	    }

        // Calculate the probabilities for being at all cell inside the board
        // after k moves
	    double ans = 0;
	    for (int i = 0; i < n; i++) {
	        for (int j = 0; j < n; j++) {
	            ans += cur[i][j];
	        }
	    }
	    return ans;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N, start_x, start_y, steps;
		cin >> N >> start_x >> start_y >> steps;
		Solution ob;
		double ans = ob.findProb(N, start_x, start_y, steps);
		cout << fixed << setprecision(6) << ans <<"\n";
	}  
	return 0;
}