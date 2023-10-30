MOD = 998244353
k, n = map(int, input().split())
N = 1 << k
g = [0]*N
g[0] = 1
for i in range(1, N):
    g[i] = g[i-1]*i % MOD

inv = [0]*N
inv[N-1] = pow(g[N-1], MOD-2, MOD)
for i in range(N-2, -1, -1):
    inv[i] = inv[i+1]*(i+1) % MOD

f = [0]*N
for i in range(N):
    f[i] = g[N-1]*inv[i] % MOD * inv[N-1-i] % MOD

for _ in range(n):
    a = [0]*N
    for i in range(N):
        for j in range(i+1):
            a[i] = (a[i] + f[j]*f[i-j]) % MOD
    f = a

print(*f)
