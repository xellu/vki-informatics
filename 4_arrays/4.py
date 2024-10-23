import random

N = [random.randint(0, 20) for _ in range(15)]
X = random.randint(0, 20)

print(f"{X=}")
print(N)

for i in range(len(N)):
    if N[i] % 5 == 0:
        N.insert(i+1, X)
    
print(N)