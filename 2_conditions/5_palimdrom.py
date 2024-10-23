a = int(input("a="))
b = int(input("b="))

def is_palindrome(num):
    return str(num) == str(num)[::-1]

print(f"{is_palindrome(a)=}")
print(f"{is_palindrome(b)=}")

