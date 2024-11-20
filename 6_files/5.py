#Дан файл f содержащий целые числа. Количество чисел в файле кратно 4. Первые два числа задают координаты (в декартовой системе) первой точки отрезка, следующие два числа – второй точки. Записать в файл f1 координаты и значение длины отрезка, имеющего минимальную длину.
import math
f = open('f.txt')
f1 = open('f1.txt', 'w')
min_length = 100
for line in f:
    x1, y1, x2, y2 = map(int, line.split())
    length = math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)
    if length < min_length:
        min_length = length
        min_x1, min_y1, min_x2, min_y2 = x1, y1, x2, y2
        
f1.write(f'{min_x1} {min_y1} {min_x2} {min_y2} {min_length}')
f.close()
f1.close()