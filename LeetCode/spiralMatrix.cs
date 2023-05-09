public class Solution {
    public IList<int> SpiralOrder(int[][] matrix) {
        List<int> ans = new();
        int[,] dir = new int[,] {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int[] mov = new int[] {matrix[0].Length, matrix.Length - 1};
        int i = 0, r = 0, c = -1;
        while (true) 
        {
            if (mov[i % 2] <= 0) 
                break;
            for (int j = 0; j < mov[i % 2]; j++) 
            {
                r += dir[i, 0];
                c += dir[i, 1];
                ans.Add(matrix[r][c]);
            }
            mov[i % 2]--;
            i = (i + 1) % 4;
        }
        return ans;    
    }
}