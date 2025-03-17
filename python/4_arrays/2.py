import random

nums = [random.randint(0, 100) for _ in range(15)]
print(nums)

while True:
    num = int(input("number: "))
    if num in nums:
        print(f"index: {nums.index(num)}")
    else:
        print("not in array")