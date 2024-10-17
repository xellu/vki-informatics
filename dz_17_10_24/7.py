#Написать программу, заполняющую двухмерный список, состоящий из 5 строк и 5 столбцов целыми числами от 1 до 25 (1, 2, 3, ...  24, 25).  Числа должны быть расставлены в случайные места двумерного списка. 

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