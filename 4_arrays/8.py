import random

def create_matrix(x, y):
    return [[random.randint(11, 111) for _ in range(x)] for _ in range(y)]

def get_min_max(matrix):
    min_row = [9999]
    max_row = [0]
    min_num = 9999
    max_mun = 0

    for row in matrix:
        if max(row) > max(max_row):
            max_row, max_num = row, max(row)
            continue

        if min(row) < min(min_row):
            min_row, min_num = row, min(row)

    return min_row, max_row, min_num, max_num

matrix = create_matrix(5, 5)

print(matrix)

min_row, max_row, min_num, max_num = get_min_max(matrix)
matrix[matrix.index(min_row)], matrix[matrix.index(max_row)] = max_row.copy(), min_row.copy()

print(matrix)

print(f"{min_num=} {max_num=}")