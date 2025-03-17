import random

N = [random.randint(0, 20) for _ in range(15)]

X = random.randint(0, 20)

print(f"{X=}")
print(N)

indexes = []
for i, num in enumerate(N):
    #print(i)
    if num % 5 == 0:
        indexes.append(i+1)
   
for offset, index in enumerate(indexes):
    N.insert(index+offset, X)

print(N)