#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> reluctance(N);
    for (int i = 0; i < N; i++) {
        cin >> reluctance[i];
    }

    vector<int> currentOrder(N);
    for (int i = 0; i < N; i++) {
        cin >> currentOrder[i];
    }

    vector<int> intendedOrder(N);
    for (int i = 0; i < N; i++) {
        cin >> intendedOrder[i];
    }

    int cost = 0;

    for (int i = 0; i < N; i++) {
        if (currentOrder[i] != intendedOrder[i]) {
            int j = i;
            while (currentOrder[j] != intendedOrder[i]) {
                j++;
            }
            while (j > i) {
                swap(currentOrder[j], currentOrder[j - 1]);
                cost += reluctance[j] + reluctance[j - 1];
                j--;
            }
        }
    }

    cout << cost << endl;

    return 0;
}
