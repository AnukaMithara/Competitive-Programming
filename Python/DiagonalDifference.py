
import math
import os
import random
import re
import sys



def diagonalDifference(arr):
    # Write your code here
    n = len(arr)
    left_sum = 0
    right_sum = 0
    for i in range(n):
        left_sum += arr[i][i]
        right_sum += arr[i][n-i-1]
    return abs(left_sum - right_sum)

if __name__ == '__main__':
    #fptr = open(os.environ['OUTPUT_PATH'], 'w')
    n = int(input().strip())
    arr = []
    for _ in range(n):
        arr.append(list(map(int, input().rstrip().split())))
    result = diagonalDifference(arr)
    print(result)
    #fptr.write(str(result) + '\n')
    #fptr.close()

#fptr.write(str(result) + '\n')

#fptr.close()
