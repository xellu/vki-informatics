text = input("text> ")
words = text.split()
min_word = min(words, key=len)
max_word = max(words, key=len)
words.remove(min_word)
words.remove(max_word)

print(" ".join(words))