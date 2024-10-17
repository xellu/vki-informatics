import random

N = [random.randint(40, 80) for _ in range(10)]
print(N)

N = [i for n, i in enumerate(N) if n % 2 == 0]
print(N)