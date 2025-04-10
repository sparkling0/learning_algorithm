from math import log2

n = 23333333
eps = 1e-4

for x in range(1, n):
    h = -(x**2 * (log2(x/n))  +  (n-x)**2 * log2((n-x)/n)) / n
    if abs(h - 11625907.5798) < eps:
        print(x)
        print(h)
        break

