def check(seq, l):
    if l == 2:
        return seq == ["0", "1"]
    l //= 2
    left = seq[:l]
    right = seq[l:]
    return (check(left, l) or check(left[::-1], l)) and check(right, l)


n, k = [int(e) for e in input().split()]
l = 2**k
for _ in range(n):
    i = input().split()
    print("yes" if check(i, l) else "no")
