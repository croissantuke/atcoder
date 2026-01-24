import math
import sys
from collections import Counter

it = iter(sys.stdin.buffer.read().split())
n = int(next(it))
q = int(next(it))
pts = [(int(next(it)), int(next(it))) for _ in range(n)]
keys = [
    (
        x // (g := math.gcd(abs(x), abs(y))) if (x or y) else (0),
        y // g if (x or y) else (0),
    )
    for x, y in pts
]
cnt = Counter(keys)
uniq = list(cnt.keys())
uniq.sort(key=lambda k: math.atan2(k[1], k[0]))
idx = {k: i for i, k in enumerate(uniq)}
arr = [cnt[k] for k in uniq]
K = len(arr)
pref = [0] * (K + 1)
for i in range(K):
    pref[i + 1] = pref[i] + arr[i]
total = pref[K]
key_idx = [idx[k] for k in keys]
out = []
for _ in range(q):
    a = int(next(it)) - 1
    b = int(next(it)) - 1
    ia = key_idx[a]
    ib = key_idx[b]
    if ia >= ib:
        out.append(str(pref[ia + 1] - pref[ib]))
    else:
        out.append(str(total - (pref[ib] - pref[ia + 1])))
sys.stdout.write("\n".join(out))
