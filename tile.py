# hilariously slow

from pprint import pprint

n, m = map(int, input().split())
a = [int(input()) for _ in range(n)]

dp = [dict() for _ in range(n)]
sqr = [i**2 for i in range(1, 101)]

for i, v in enumerate(sqr):
    dp[0][v] = (a[0] - i - 1) ** 2

for i in range(1, n):
    tmp = []
    for j, s in enumerate(sqr):
        tmp.append((s, (j + 1 - a[i]) ** 2))
    for val, cost in dp[i - 1].items():
        for vt, ct in tmp:
            dp[i][val + vt] = min(dp[i].get(val + vt, 10000000), cost + ct)
# pprint(dp)
print(dp[-1][m])
