# https://leetcode.com/problems/longest-substring-without-repeating-characters/
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        lo = 0
        hi = 0
        maxLen = 1
        n = len(s)
        if n == 0:
            return 0
        chars = {s[0]}
        
        
        while (hi+1 < n):
            hi += 1
            if (s[hi] in chars):
                # Reorient the starting to remove the repition
                while (lo <= hi):
                    charRem = s[lo]
                    chars.remove(charRem)
                    lo += 1
                    if (charRem == s[hi]):
                        break
            chars.add(s[hi])
            if ((hi - lo + 1) > maxLen):
                maxLen = hi - lo + 1
        return maxLen
        