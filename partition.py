n = int(input())
p = [0] * (n + 1)
pentagonal = [1, 2, 5, 7, 12, 15, 22, 26, 35, 40, 51, 57, 70, 77, 92, 100]
sign = [
    True,
    True,
    False,
    False,
    True,
    True,
    False,
    False,
    True,
    True,
    False,
    False,
    True,
    True,
    False,
    False,
]
p[0] = 1
for i in range(1, n + 1):
    for j in range(len(pentagonal)):
        # for j, e in enumerate(pentagonal):
        x = i - pentagonal[j]
        if x < 0:
            break
        if sign[j]:
            p[i] += p[x]
        else:
            p[i] -= p[x]
print(p[n])
