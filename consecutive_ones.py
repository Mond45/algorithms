def g(x, l, k, a=0, c=0):
    if not l:
        if a:
            print(x)
        return
    g(x + "0", l - 1, k, a, 0)
    g(x + "1", l - 1, k, a or c + 1 == k, c + 1)


n, k = [int(e) for e in input().split()]
g("", n, k)
