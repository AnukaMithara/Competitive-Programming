#include <iostream>
#include <vector>
#include <climits>

int main() {
    int T;
    std::cin >> T;
    for(int t = 0; t < T; t++) {
        int N, M, K, B;
        std::cin >> N >> M >> K >> B;
        std::vector<std::vector<int>> grid(N, std::vector<int>(M));
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                std::cin >> grid[i][j];
            }
        }

        std::vector<std::vector<int>> dp(N, std::vector<int>(M, INT_MIN));
        dp[0][0] = grid[0][0];
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++) {
                if (i > 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + grid[i][j]);
                    if (i >= K) {
                        int min_val = INT_MAX;
                        for (int k = i; k > i - K; k--) {
                            min_val = std::min(min_val, grid[k][j]);
                        }
                        if (min_val >= B) {
                            dp[i][j] = std::max(dp[i][j], dp[i - K][j] + grid[i][j]);
                        }
                    }
                }
                if (j > 0) {
                    dp[i][j] = std::max(dp[i][j], dp[i][j - 1] + grid[i][j]);
                    if (j >= K) {
                        int min_val = INT_MAX;
                        for (int k = j; k > j - K; k--) {
                            min_val = std::min(min_val, grid[i][k]);
                        }
                        if (min_val >= B) {
                            dp[i][j] = std::max(dp[i][j], dp[i][j - K] + grid[i][j]);
                        }
                    }
                }
            }
        }

        if (dp[N - 1][M - 1] == INT_MIN) {
            std::cout << "Case " << t + 1 << ": IMPOSSIBLE" << std::endl;
        } else {
            std::cout << "Case " << t + 1 << ": " << dp[N - 1][M - 1] << std::endl;
        }
    }
    return 0;
}
