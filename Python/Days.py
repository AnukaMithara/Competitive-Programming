def check(mid, K, A):
    cnt = 0
    for i in range(len(A)-1, -1, -1):
        if A[i] > mid:
            return False
        if cnt + A[i] > mid:
            cnt = 0
        cnt += A[i]
    return True

def max_total_score(N, K, A):
    left, right = max(A), sum(A)
    while left < right:
        mid = (left + right) // 2
        if check(mid, K, A):
            right = mid
        else:
            left = mid + 1
    return left

N, K = map(int, input().split())
A = list(map(int, input().split()))
print(max_total_score(N, K, A))


# You are assigned a series of tasks to complete over N days, with each task numbered from 1 to N and must be completed in this order. 

# You can accomplish a maximum of K tasks per day and aim to complete the tasks in the shortest time possible. While adhering to these constraints, you seek a schedule that ensures a balanced workload each day. More precisely, each task i is associated with a specific score a. For a given schedule, each day's score is determined by the maximum score of all the tasks completed on that day. 

# Finally, the scores of each day are summed to give the total score of the schedule. The objective is to find the maximum possible total score of the schedule while minimizing the number of days required to complete all the tasks

# Input Format
# The first line contains two space-separated integers N and K (1 ≤ K ≤ N ≤ 10⁶).
# The next line contains N space separated integers aᵢ (1 ≤ aᵢ ≤ 10⁹).

# Output Format
# Output a single integer, the maximum possible total score.

# Sample Input 0
# 5 3
# 2 5 7 1 4

# Sample Output 0
# 12

