import string

def encrypt(text):
    output = ""
    for char in text:
        if char not in string.ascii_letters:
            output += char
            continue

        if char.lower() == "a":
            output += "y" if char.islower() else "Y"
            continue

        if char.lower() == "b":
            output += "z" if char.islower() else "Z"
            continue

        output += chr(ord(char)-2)
    return output

def decrypt(text):
    output = ""
    for char in text:
        if char not in string.ascii_letters:
            output += char
            continue

        if char.lower() == "y":
            output += "a" if char.islower() else "A"
            continue

        if char.lower() == "z":
            output += "b" if char.islower() else "B"
            continue

        output += chr(ord(char)+2)
    return output

print(f"1: Encrypt\n2: Decrypt")
choice = input("choice> ")
text = input("text> ")
 
if choice == "1":
    print(f"{encrypt(text)=}")
elif choice == "2":
    print(f"{decrypt(text)=}")
else:
    print("invalid choice")