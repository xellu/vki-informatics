#write anything into f1.txt

f1 = open("f1.txt", "r", encoding="utf-8")
f2 = open("f2.txt", "w", encoding="utf-8")

f2.write(
    "\n".join(list(reversed(f1.read().splitlines())))
)