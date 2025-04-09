t = []

for i in range(1,521):
    s = input().split(":")
    if i % 2 == 0:
        x = 3600 * int(s[0]) + 60 * int(s[1]) + int(s[2])
        t.append(x)

print(t)
print(sum(t))
print(len(t))