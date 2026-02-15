import sys

it = iter(sys.stdin.buffer.read().split())
n = int(next(it))
q = int(next(it))
a = [0] + [int(next(it)) for _ in range(n)]
bit = [0] * (n + 1)


def add(i, v):
    while i <= n:
        bit[i] += v
        i += i & -i


def s(i):
    r = 0
    while i:
        r += bit[i]
        i -= i & -i
    return r


for i in range(1, n + 1):
    add(i, a[i])
out = []
for _ in range(q):
    t = int(next(it))
    if t == 1:
        x = int(next(it))
        if a[x] != a[x + 1]:
            d = a[x + 1] - a[x]
            a[x] += d
            a[x + 1] -= d
            add(x, d)
            add(x + 1, -d)
    else:
        l = int(next(it))
        r = int(next(it))
        out.append(str(s(r) - s(l - 1)))
sys.stdout.write("\n".join(out))
