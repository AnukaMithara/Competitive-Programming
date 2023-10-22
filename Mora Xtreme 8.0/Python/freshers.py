from sys import stdin, stdout
from bisect import bisect_right

def solve():
    n, m = map(int, stdin.readline().split())
    h = list(map(int, stdin.readline().split()))
    h.sort()
    s = [0]*(n+1)
    for i in range(n):
        s[i+1] = s[i] + h[i]
    for _ in range(m):
        l, r, x = map(int, stdin.readline().split())
        l -= 1
        r -= 1
        if s[r+1]-s[l] < x:
            stdout.write("-1\n")
        else:
            lo = 0
            hi = n
            while lo < hi:
                mid = (lo+hi)//2
                if h[mid] <= x/(r-l+1):
                    lo = mid+1
                else:
                    hi = mid
            stdout.write(str(h[lo]) + "\n")

solve()
