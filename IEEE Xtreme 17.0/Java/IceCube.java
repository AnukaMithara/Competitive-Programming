import java.util.*;
import java.io.*;

public class Main {
    static int[][] grid;
    static int[][][] dp;
    static int n, m, k, b;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        int caseNumber = 1;
        while (t-- > 0) {
            String[] s = br.readLine().split(" ");
            n = Integer.parseInt(s[0]);
            m = Integer.parseInt(s[1]);
            k = Integer.parseInt(s[2]);
            b = Integer.parseInt(s[3]);
            grid = new int[n][m];
            dp = new int[n][m][k];
            for (int i = 0; i < n; i++) {
                s = br.readLine().split(" ");
                for (int j = 0; j < m; j++) {
                    grid[i][j] = Integer.parseInt(s[j]);
                }
            }
            for (int[][] row : dp)
                for (int[] col : row)
                    Arrays.fill(col, -1);
            int ans = dfs(0, 0, 0);
            if (ans < 0)
                System.out.println("Case " + caseNumber + ": " + "IMPOSSIBLE");
            else
                System.out.println("Case " + caseNumber + ": " + dfs(0, 0, 0));

            caseNumber++;
        }
    }

    static int dfs(int x, int y, int z) {
        if (x == n - 1 && y == m - 1)
            return grid[x][y];
        if (dp[x][y][z] != -1)
            return dp[x][y][z];
        int ans = Integer.MIN_VALUE;
        if (x + 1 < n) {
            if (grid[x + 1][y] < b && z + 1 < k)
                ans = Math.max(ans, grid[x][y] + dfs(x + 1, y, z + 1));
            else if (grid[x + 1][y] >= b)
                ans = Math.max(ans, grid[x][y] + dfs(x + 1, y, 0));
        }
        if (y + 1 < m) {
            if (grid[x][y + 1] < b && z + 1 < k)
                ans = Math.max(ans, grid[x][y] + dfs(x, y + 1, z + 1));
            else if (grid[x][y + 1] >= b)
                ans = Math.max(ans, grid[x][y] + dfs(x, y + 1, 0));
        }
        return dp[x][y][z] = ans;
    }
}
