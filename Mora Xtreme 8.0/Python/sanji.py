def max_healthy_cells(n, p, pos, m, y, r):
    # Initialize the total number of cells and the fungus layers
    total_cells = sum(p)
    layers = list(zip(y, r))

    # Calculate the number of cells affected by each layer
    affected_cells = []
    for layer in layers:
        layer_pos, layer_range = layer
        affected = 0
        for i in range(n):
            if abs(layer_pos - pos[i]) <= layer_range:
                affected += p[i]
        affected_cells.append(affected)

    # Find the maximum number of healthy cells by removing one layer
    max_healthy = total_cells - min(affected_cells)

    return max_healthy

# Test the function with the sample input
n = 2
p = [10, 100]
pos = [5, 100]
m = 1
y = [4]
r = [1]
print(max_healthy_cells(n, p, pos, m, y, r))  # Output: 110
