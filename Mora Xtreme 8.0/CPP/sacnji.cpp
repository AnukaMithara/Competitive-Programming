#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; // Number of cell groups
    cin >> n;

    vector<int> cells(n);
    for (int i = 0; i < n; i++) {
        cin >> cells[i]; // Number of cells in the ith cell group
    }

    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i]; // Position of the ith cell group on the one-dimensional cell row
    }

    int m; // Number of fungus layers
    cin >> m;

    vector<int> layers(m);
    for (int i = 0; i < m; i++) {
        cin >> layers[i]; // Location of the ith layer on the cell row
    }

    vector<int> ranges(m);
    for (int i = 0; i < m; i++) {
        cin >> ranges[i]; // Range of the ith fungus layer
    }

    // Calculating the maximum number of healthy cells
    int totalHealthyCells = 0;
    for (int i = 0; i < n; i++) {
        bool isAffected = false;
        for (int j = 0; j < m; j++) {
            if (positions[i] >= layers[j] - ranges[j] && positions[i] <= layers[j] + ranges[j]) {
                isAffected = true;
                break;
            }
        }
        if (!isAffected) {
            totalHealthyCells += cells[i];
        }
    }

    cout << totalHealthyCells << endl;

    return 0;
}
