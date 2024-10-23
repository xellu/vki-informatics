#v1---
a = 1
b = 3
c = None

print(f"{a=}, {b=}")
c = b
b = a
a = c
del c
print(f"{a=}, {b=}")

print("--------")

#v2----
x = 1
y = 3

print(f"{x=}, {y=}")
x=x+y
y=x-y
x=x-y
print(f"{x=}, {y=}")


