def generate(l, needed, s=""):
    if l == 0:
        if needed == 0:
            print(s)
        return
    generate(l - 1, needed, s + "0")
    if needed > 0:
        generate(l - 1, needed - 1, s + "1")


n, l = [int(e) for e in input().split()]
generate(l, n)
