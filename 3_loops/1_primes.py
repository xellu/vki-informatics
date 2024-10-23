count = abs(int(input("amount to query> ")))

for i in range(1, count+1):
    for j in range(1, i):
        if i == j or j == 1:
            continue 

        if i % j == 0:
            break
    else:
        print(i)
