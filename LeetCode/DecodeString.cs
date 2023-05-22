public class Solution {
    public string DecodeString(string s) {
        return GetRepString(ref s, 0).Item1;
    }

    private (string, int) GetRepString(ref string s, int start) {
        int ind = start;
        var seq = new StringBuilder();
        while (ind < s.Length && s[ind] != ']') {
            if (Char.IsDigit(s[ind])) {
                int nextStart = s.IndexOf('[', ind);
                int rep = int.Parse(s.Substring(ind, nextStart-ind));
                (string repStr, int nextEnd) = GetRepString(ref s, nextStart+1);
                for (int i = 0; i < rep; i++) {
                    seq.Append(repStr);
                }
                ind = nextEnd;
            } else {
                seq.Append(s[ind]);
            }
            ind++;
        }
        return (seq.ToString(), ind);
    }
}