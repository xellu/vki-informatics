text = input("text to process> ")

def remove_brackets(text):
    active = True
    output = ""
    for char in text:
        
        match char:
            case "(":
                active = False
            case ")":
                active = True
            case _:
                if not active: continue

                output += char
    
    return output

print(f"{remove_brackets(text)=}")