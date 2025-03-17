countries = open("gos.txt", "r").read()
capitals = open("capital.txt", "r").read().splitlines()

while True:
    print("\nlookup using:")
    print("1 - country")
    print("2 - capital city")

    c = input(">")
    
    userinput = input("query> ").lower()
    found = False

    if c == "1":
        for country in countries.splitlines():
            names = country.split(";") + country.lower().split(";")
            if userinput in names:
                print(f"The capital of {names[0]} is '{capitals[countries.index(country)]}'")
                
                found = True
                break

    else:
        for capital in capitals:
            if userinput == capital.lower():
                country = countries.splitlines()[capitals.index(capital)].split(";")[0]

                print(f"{capital} is the capital city of '{country}'")

                found = True
                break