#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

bool dfs(vector<vector<int>>& matrix, int x, int W, int H) {
    if (x < 0 || x >= W) {
        return false;
    }
    if (x == W - 1) {
        return true;
    }
    if (matrix[x][0] != 1) {
        return false;
    }
    matrix[x][0] = 2;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (dfs(matrix, x + i, W, H)) {
                return true;
            }
        }
    }
    return false;
}

string canGo(vector<vector<int>>& matrix, int W, int H) {
    for (int i = 0; i < W; i++) {
        if (dfs(matrix, i, W, H)) {
            return "CAN";
        }
    }
    return "CAN'T";
}

void createMatrix(int W, int H, int N, int R, vector<int>& sensor_x, vector<int>& sensor_y) {
    vector<vector<int>> matrix(W, vector<int>(H, 1));
    for (int i = 0; i < N; i++) {
        int x = sensor_x[i];
        int y = sensor_y[i];
        for (int j = 0; j < W; j++) {
            for (int k = 0; k < H; k++) {
                if (hypot(x - j, y - k) <= R) {
                    matrix[j][k] = 0;
                }
            }
        }
    }
    cout << canGo(matrix, W, H) << endl;
}

int main() {
    int T;
    cin >> T; // Number of test cases

    for (int t = 0; t < T; t++) {
        int W, H, N, R;
        cin >> W >> H; // Width and Height of the living room
        cin >> N >> R; // Number of sensors and the radius

        vector<int> sensor_x(N);
        vector<int> sensor_y(N);

        // Input the x-coordinates of sensors
        for (int i = 0; i < N; i++) {
            cin >> sensor_x[i];
        }

        // Input the y-coordinates of sensors
        for (int i = 0; i < N; i++) {
            cin >> sensor_y[i];
        }

        createMatrix(W, H, N, R, sensor_x, sensor_y);
        // Checking if the rat can pass safely
        // if (canRatPass(W, H, N, R, sensor_x, sensor_y)) {
        //     cout << "CAN" << endl;
        // } else {
        //     cout << "CAN'T" << endl;
        // }
    }

    return 0;
}
