import random

X = 5
Y = 5

N = [[0 for _ in range(X)] for _ in range(Y)]

nums = [i+1 for i in range(X*Y)]
random.shuffle(nums)

for i in range(Y):
    for j in range(X):
        N[i][j] = nums.pop()

for row in N:
    print(row)