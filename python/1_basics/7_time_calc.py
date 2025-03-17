s = int(input("seconds>"))

m = s // 60
h = m // 60

s -= m*60
m -= h*60

print(f"{h=}, {m=}, {s=}")
