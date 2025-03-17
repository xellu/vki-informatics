#create input.txt, write any amount of integers

f1 = open("input.txt", "r")
f2 = open("output.txt", "w")

data = list(f1.read())
f1.close()

result = 1
for number in data:
    result *= int(number)
    
f2.write(str(result))
f2.close()