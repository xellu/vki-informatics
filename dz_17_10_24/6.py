import random

def countrange(nums, min, max):
    count = 0
    for num in nums:
        if min <= num < max:
            count += 1
    return count

nums1 = [random.randint(1, 50) for _ in range(20)]

print(f"{nums1=}")
print(f"{countrange(nums1, 10, 30)=}")
