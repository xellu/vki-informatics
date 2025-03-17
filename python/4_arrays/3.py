def shift(array):
    array.append(array.pop(0))
    return array


nums = [i+1 for i in range(15)]
for _ in nums:
    print(nums)
    nums = shift(nums)