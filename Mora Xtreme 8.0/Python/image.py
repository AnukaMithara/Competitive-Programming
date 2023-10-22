import numpy as np

def findMarginGradientAndYIntercept(image):
    # Your logic here
    m = 0
    c = 0
    return m, c

N = int(input())
images = []

for _ in range(N):
    image = np.zeros((50, 50), dtype=int)
    for j in range(50):
        for k in range(50):
            pixel = input()
            image[j][k] = 1 if pixel == '1' else 0
    images.append(image)

# Print out each image in the list
for i in range(N):
    m, c = findMarginGradientAndYIntercept(images[i])
    print(m, c)
