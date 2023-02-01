result = list()
cnt = dict()


def generate(l):
    if len(result) == len(l):
        print("".join(result))
    else:
        for e in cnt:
            if cnt[e] > 0:
                cnt[e] -= 1
                result.append(e)
                generate(l)
                result.pop()
                cnt[e] += 1


l = list("1123")
for e in l:
    if e not in cnt:
        cnt[e] = 0
    cnt[e] += 1
generate(l)
