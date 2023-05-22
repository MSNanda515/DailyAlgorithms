public class Solution {
    public int[] TopKFrequent(int[] nums, int k) {
        var freq = new Dictionary<int, int>();
        foreach (var it in nums) {
            if (!freq.ContainsKey(it)) {
                freq.Add(it, 0);
            }
            freq[it] += 1;
        }
        // Console.WriteLine(freq.Count);
        var freqList = new List<(int, int)>();
        foreach (var it in freq) {
            freqList.Add((it.Value, it.Key));
            // Console.WriteLine(freqList.Count);
        }
        freqList.Sort();
        freqList.Reverse();
        var ans = new int[k];
        // Console.WriteLine(freqList.Count);
        for (int i = 0; i < k; i++) {
            ans[i] = freqList[i].Item2;
        }
        return ans;
    }
}