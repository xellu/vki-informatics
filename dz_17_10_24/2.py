import random

nums = [random.randint(0, 100) for _ in range(15)]
print(nums)

while True:
    num = int(input("Введите число: "))
    if num in nums:
        print(f"Индекс: {nums.index(num)}")
    else:
        print("не в списке")