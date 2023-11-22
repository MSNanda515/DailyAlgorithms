class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int fst, lst;
        vector<bool> seen(26, false);
        int ans = 0;
        int l, r;
        int ptr, un = 0;
        for (int c = 'a'; c <= 'z'; c++) {
            for (l = 0; l < s.size() && s[l] != c; l++);
            if (l == s.size()) { continue; }
            for (r = s.size() - 1; r >= 0 && s[r] != c; r--);
            if (r <= l) { continue; }
            for (int i = 0; i < 26; i++) { seen[i] = false; }
            un = 0;

            for (int i = l+1; i < r; i++) {
                ptr = s[i] - 'a';
                if (!seen[ptr]) {
                    seen[ptr] = true;
                    un++;
                    if (un == 26) { break; }
                }
            }
            ans += un;
        }
        return ans;
    }
};