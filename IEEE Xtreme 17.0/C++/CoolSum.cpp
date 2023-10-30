#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX = 1e6 + 5;

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = (int)((long long)res * a % MOD);
        a = (int)((long long)a * a % MOD);
        b >>= 1;
    }
    return res;
}

void precompute(vector<int>& fact, vector<int>& invfact) {
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (int)((long long)i * fact[i - 1] % MOD);
        invfact[i] = power(fact[i], MOD - 2);
    }
}

int binomialCoeff(int n, int k, vector<int>& fact, vector<int>& invfact) {
    if (k > n) return 0;
    return (int)((long long)fact[n] * invfact[k] % MOD * invfact[n - k] % MOD);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> fact(MAX), invfact(MAX);
    precompute(fact, invfact);

    int k, n;
    cin >> k >> n;

    vector<int> arr(1 << k, 0);
    int mask = (1 << k) - 1;

    for (int i = 0; i < n + 1; i++) {
        arr[i & mask] = (arr[i & mask] + binomialCoeff(n, i, fact, invfact)) % MOD;
    }

    for (auto &a : arr) {
        cout << a << " ";
    }
    return 0;
}
