d = int(input("D="))
e = int(input("E="))
a = int(input("A="))
b = int(input("B="))
c = int(input("C="))

if (a<=d and b <= e) or (a <= e and b <= d) or (a <= d and c <= e) or (a <= e and c <= d) or (b <= d and c <=e) or (b <= e and c <= d):
    print(True)
else:
    print(False)