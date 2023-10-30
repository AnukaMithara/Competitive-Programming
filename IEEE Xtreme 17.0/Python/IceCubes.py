def max_path_sum(grid, N, M, K, B):
    dp = [[-1 for _ in range(M)] for _ in range(N)]
    dp[0][0] = grid[0][0]
    for i in range(N):
        for j in range(M):
            if i > 0:
                dp[i][j] = max(dp[i][j], dp[i-1][j] + grid[i][j])
            if j > 0:
                dp[i][j] = max(dp[i][j], dp[i][j-1] + grid[i][j])
            if i > 0 and j > 0 and (grid[i-1][j] < B and grid[i][j-1] < B):
                count = 2
                x, y = i-2, j-1
                while x >= 0 and grid[x][y] < B:
                    count += 1
                    x -= 1
                if count < K:
                    dp[i][j] = max(dp[i][j], dp[x][y] + sum(grid[r][y] for r in range(x+1, i+1)) + grid[i][j])
                count = 2
                x, y = i-1, j-2
                while y >= 0 and grid[x][y] < B:
                    count += 1
                    y -= 1
                if count < K:
                    dp[i][j] = max(dp[i][j], dp[x][y] + sum(grid[x][c] for c in range(y+1, j+1)) + grid[i][j])
    return dp[N-1][M-1]
print(max_path_sum([[6,6,1],[1,1,5]], 2, 3, 2, 5))
print(max_path_sum([[5,5,6,5],[3,6,3,5],[7,1,8,4]], 3, 4, 3, 7))
print(max_path_sum([[9,5,3,3],[9,1,1,5],[3,1,3,5],[1,1,3,2]], 4, 4, 3 ,6))
