n, h0, a, c, q = map(int, input().split())
heights = [0] * n
heights[n - 1] = h0

for i in range(n - 2, -1, -1):
    heights[i] = (a * heights[i + 1] + c) % q

count = 0
first = True

for i in range(0, n - 1):
    first = True
    close_height = heights[i + 1]  # visible max height

    for j in range(i + 1, n):
        first = False
        if heights[j] >= close_height and not first:
            close_height = heights[j]
            count += 1
        elif not first:
            break

        first = False

print(count)
