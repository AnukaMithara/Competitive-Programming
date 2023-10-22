#include <iostream>

using namespace std;

int dp[1010][1010];
int nums[1010];

int main() {

    int n, s;
    cin >> n >> s;

    for (int i = 0; i < n; i++)
        cin >> nums[i];

    dp[0][0] = 1; // manually add the first
    dp[0][nums[0]] = 1;

    for (int i = 1; i < n; i++) { // j is the number
        dp[i][0] = 1;
        for (int j = 1; j <= s; j++) { // i is the sum
            if (j - nums[i] >= 0) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }

    }
    cout << dp[n - 1][s] << endl;
    return 0;
}
