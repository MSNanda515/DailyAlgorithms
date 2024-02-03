class Solution {
    
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) { return 0; }
        int maxStr = 1;
        unordered_map<char, int> charPos;
        int beg = 0, end = 0;
        while (end < s.size()) {
            if (charPos.find(s[end]) != charPos.end() && charPos[s[end]] >= 0) {
                while (beg <= charPos[s[end]]) {
                    charPos[s[beg]] = -1;
                    beg++;
                }
            }
            charPos[s[end]] = end;
            maxStr = max(maxStr, end - beg + 1);
            end++;
        }
        return maxStr;
    }
};