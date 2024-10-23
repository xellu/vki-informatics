nums = []

for i in range(5):
    nums.append(
        int(input(f"nums[{i}]="))
    )

print(f"{min(nums)=}")
print(f"{max(nums)=}")
