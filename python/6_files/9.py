#create f1.txt, write any amount of integers

with open('f1.txt', 'r') as f:
    data = f.read().splitlines()
    data = [int(i) for i in data]
    data.sort()
    
    with open('f2.txt', 'w') as f2:
        f2.write('\n'.join([str(i) for i in data]))
        