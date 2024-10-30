text = input("text> ")

reset = 3
new_text = ""

for char in text:
    if char.lower() == "o":
        reset -= 1

    if reset <= 0:
        reset = 3
        continue

    new_text += char

print(new_text)