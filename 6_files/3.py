#do not create f1.txt

import random
import string
import os

S1 = random.choice(string.ascii_lowercase)

def generate():
    if "f1.txt" in os.listdir("."):
        os.remove("f1.txt")

    f1 = open("f1.txt", "a")
    for _ in range(10):
        f1.write("".join(random.choice(string.ascii_lowercase) for _ in range(10)) + "\n")

    f1.close()

def get_s1():
    print(f"{S1=}")
    f1 = open("f1.txt", "r")

    lns = []
    for ln in f1.read().splitlines():
        if S1 in ln:
            lns.append(ln)
        print(f"{ln} - {S1 in ln}")

    f1.close()
    open("f2.txt", "w").write("\n".join(lns))


generate()
get_s1()