import random
import string

m = random.randint(0,9)
n = 777

text = "".join(random.choice(string.digits+string.ascii_letters) for i in range(10))

if random.choice([True, False]):
    text = f"{m}{text}{n}"

print(f"{text=}")

if text.startswith(str(m)) and text.endswith(str(n)):
    #do something if its true
    print(True)
else:
    print(False)