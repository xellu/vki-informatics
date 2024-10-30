import string

text = input("text> ")

def swapcase(text):
    output = ""
    for char in text:
        if char not in string.ascii_letters:
            output += char
            continue

        if char in string.ascii_uppercase:
            output += chr(ord(char)+32)
            continue
        
        output += chr(ord(char)-32)
    return output

print(f"{swapcase(text)=}")