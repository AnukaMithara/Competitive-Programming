def minimum_cost_to_move_boxes(N, cost, current, target):
    swaps = 0
    total_cost = 0

    for i in range(N):
        if current[i] != target[i]:
            for j in range(i + 1, N):
                if current[j] == target[i]:
                    while j != i:
                        current[j], current[j - 1] = current[j - 1], current[j]
                        total_cost += cost[j - 1] + cost[j]
                        swaps += 1
                        j -= 1
                    break
    return total_cost


# Sample Input
N = 3
cost = [1, 1, 1]
current = [3, 2, 1]
target = [1, 2, 3]

# Function Call
result = minimum_cost_to_move_boxes(N, cost, current, target)
print(result)
