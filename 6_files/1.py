#write anything into f1.txt

open("f2.txt", "w", encoding="utf-8").write(
    open("f1.txt", "r", encoding="utf-8").read()
)