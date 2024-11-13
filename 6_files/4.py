import random
import string
import os

def generate():
    if "f1.txt" in os.listdir("."):
        os.remove("f1.txt")

    f1 = open("f1.txt", "a")
    for _ in range(10):
        f1.write("".join(random.choice(string.digits) for _ in range(2)) + "\n")

    f1.close()

def counter(num):
    count = 0
    num = abs(num)
    for i in range(1,num):
        if num % i == 0:
            count += 1

    return count


def lookup():
    f1 = open("f1.txt", "r")
    
    out = []
    for ln in f1.read().splitlines():
        count = counter(int(ln))
        if count == 3:    
            out.append(ln)

        print(f"{ln} - {count} - {count==3}")

    f1.close()
    open("f2.txt", "w").write("\n".join(out))

generate()
lookup()