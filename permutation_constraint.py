chosen = {}
constraint = []


def permute(k, p: list = []):
    if len(p) == k:
        print("".join(p))
        return
    for i in range(k):
        if chosen[i]:
            continue
        con = False
        for c in constraint:
            if i == c[1] and not chosen[c[0]]:
                con = True
                break
        if (con):continue
        chosen[i] = True
        p.append(str(i))
        permute(k, p)
        chosen[i] = False
        p.pop()


n, k = [int(e) for e in input().split()]
for _ in range(k):
    constraint.append([int(e) for e in input().split()])
for i in range(n):
    chosen[i] = False
permute(n)
