class Solution {
    int countSetBits(int n) {
        int bits = 0;
        while (n > 0) {
            bits += n & 1;
            n = n >> 1;
        }
        return bits;
    }
    
    int findBits(int n) {
        int bits = 0;
        while (n > 0) {
            bits += 1;
            n = n >> 1;
        }
        return bits;
    }
    
  public:
    int minVal(int a, int b) {
        // code here
        int setBitsB = countSetBits(b);
        int setBitsA = countSetBits(a);
        if (setBitsA > setBitsB) {
            int totBitsA = findBits(a);
            int mask = 0, maskPrep;
            int foundSetBits = 0, copyA = a;
            maskPrep = 1 << (totBitsA - 1);
            for (int i = 0; i < totBitsA; i++) {
                if ((maskPrep & copyA) > 0 && foundSetBits < setBitsB) {
                    foundSetBits += 1;
                    mask = mask << 1;
                    mask = mask | 1;
                } else {
                    mask = mask << 1;
                }
                maskPrep = maskPrep >> 1;
            }
            return a & mask;
        } else {
            int mask = 1;
            int ans = a;
            int diff = setBitsB - setBitsA;
            while (diff > 0) {
                if ((mask & ans) == 0) {
                    ans = ans | mask;
                    diff -= 1;
                }
                mask = mask << 1;
            }
            return ans;
        }
    }
};
