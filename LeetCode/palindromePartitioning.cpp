
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
	void findPalind(vector<vector<bool>>& palind, string& s) {
		// base case
		for (int i = 0; i < s.size(); i++) {
			palind[i][i] = true;
			if (i+1 < s.size() && s[i] == s[i+1]) {
				palind[i][i+1] = true;
			}
		}
		
		for (int gap = 2; gap < s.size(); gap++) {
			for (int i = 0; i + gap < s.size(); i++) {
				int j = gap + i;
				if (s[i] == s[j] && palind[i+1][j-1]) {
					palind[i][j] = true;
				}
			} 
		}
	}  

	void findPart(vector<vector<string>>& ans, vector<vector<bool>>& palind, vector<string>& buff, int beg, string& s) {
		if (beg == palind.size()) {
			ans.push_back(buff);
			return;
		}	
		
		for (int i = beg; i < palind.size(); i++) {
			if (palind[beg][i]) {
				buff.push_back(s.substr(beg, i-beg+1));
				findPart(ans, palind, buff, i+1, s);
				buff.pop_back();
			}
		}
	}
		

public:
    vector<vector<string>> partition(string s) {
    	vector<vector<bool>> palind(s.size(), vector<bool>(s.size(), false));    
		findPalind(palind, s);
		vector<vector<string>> ans;
		vector<string> buffer;
		findPart(ans, palind, buffer, 0, s);
		return ans;
    }

};
