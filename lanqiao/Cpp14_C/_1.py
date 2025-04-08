import datetime

a = datetime.date(2023,1,1)
sum = 0

for i in range(1,366):
    if '1' in a.strftime("%m%d%w"):
        sum += 5
    else:
        sum += 1
    a += datetime.timedelta(days=1)

print(sum)    