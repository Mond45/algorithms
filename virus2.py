def count_bit(l):
    cnt = 0
    for c in l:
        if c == "1":
            cnt += 1
    return cnt


def check(s, l):
    if l == 2:
        return True
    l //= 2
    left = s[:l]
    right = s[l:]
    c = abs(count_bit(left) - count_bit(right))
    return c <= 1 and check(left, l) and check(right, l)


n, l = [int(e) for e in input().split()]
l = 2**l
for _ in range(n):
    print("yes" if check(input().split(), l) else "no")
