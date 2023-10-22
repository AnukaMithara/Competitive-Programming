def min_time(l, p, q, S):
    i = 1
    cost = 0
    cost = [float('inf')] * (l + 1)
    cost[0] = 0
    k = 0
    while i <= l: 
        j = max(i, k)
        while j<=l and (S[i-1:j] in S[:i-1]):
            j += 1
        if j-1 != i:
            cost[j-1] = min(cost[i-1] + q, cost[j-1])
            k = j
        cost[i] = min(cost[i-1] + p, cost[i])
        i += 1
    return cost[-1]

T = int(input())
for _ in range(T):
  l, p, q = map(int, input().split())
  S = input().strip()
  print(min_time(l, p, q, S))