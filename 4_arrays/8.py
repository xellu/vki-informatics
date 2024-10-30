import random

def create_matrix(x, y):
    return [[random.randint(11, 111) for _ in range(x)] for _ in range(y)]

def get_min_max(matrix):
    min_col = 0
    max_col = 0
    min_num = 9999
    max_num = 0

    for row in matrix:
        if max(row) > max_num:
            max_num = max(row)
            max_col = row.index(max_num)
            continue

        if min(row) < min_num:
            min_num = min(row)
            min_col = row.index(min_num)

    return min_col, max_col, min_num, max_num

def display_matrix(mat):
    for row in mat:
        for n in row:
            print(f"{n}".ljust(4), end="")
        print()

matrix = create_matrix(5, 5)

display_matrix(matrix)     
print("-"*5*4)

min_col, max_col, min_num, max_num = get_min_max(matrix)

for row in matrix:
    row[min_col], row[max_col] = row[max_col], row[min_col]

display_matrix(matrix)

print(f"{min_num=}, {min_col=}, {max_num=}, {max_col=}")