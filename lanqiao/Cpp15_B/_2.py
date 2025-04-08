from math import sqrt

def gcd(a, b):
    if b == 0:
         return a
    else:
        return gcd(b, a % b)


def lcd(x, y):
    t = gcd(x, y)
    return x / t * y

# x = lcd(343720, 15)
# y = lcd(233333, 17)
# res = sqrt(4 * x * x + 4 * y * y)

a, b = 343720, 233333
t = 1
while True:
    if (15 * t) % a == 0 and (17 * t) % b == 0:
        break
    t += 1

    
res = 2 * sqrt(15**2*t**2 + 17**2*t**2)
# print(t)
# print(res)
print(1100325199.77)