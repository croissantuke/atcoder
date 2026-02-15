import sys
from functools import cmp_to_key

sys.setrecursionlimit(2000000)
I = iter(sys.stdin.read().split())


def solve():
    N = int(next(I))
    Q = int(next(I))
    P = []
    for i in range(1, N + 1):
        P.append((int(next(I)), int(next(I)), i))

    def region(x, y):
        if y < 0:
            return 0
        if y == 0 and x > 0:
            return 1
        if y > 0:
            return 2
        return 3

    def cmp(p1, p2):
        x1, y1, _ = p1
        x2, y2, _ = p2
        r1, r2 = region(x1, y1), region(x2, y2)
        if r1 != r2:
            return r1 - r2
        return (x2 * y1) - (x1 * y2)

    P.sort(key=cmp_to_key(cmp))

    groups = []
    pos = [0] * (N + 1)
    if N > 0:
        cnt = 1
        curr_idx = 0
        pos[P[0][2]] = 0
        for i in range(1, N):
            if cmp(P[i], P[i - 1]) == 0:
                cnt += 1
            else:
                groups.append(cnt)
                cnt = 1
                curr_idx += 1
            pos[P[i][2]] = curr_idx
        groups.append(cnt)

    M = len(groups)
    S = [0] * (2 * M + 1)
    G2 = groups + groups
    for i in range(2 * M):
        S[i + 1] = S[i] + G2[i]

    ans = []
    for _ in range(Q):
        a = int(next(I))
        b = int(next(I))
        ia, ib = pos[a], pos[b]
        if ia == ib:
            ans.append(groups[ia])
        elif ib < ia:
            ans.append(S[ia + 1] - S[ib])
        else:
            ans.append(S[ia + 1 + M] - S[ib])

    print("\n".join(map(str, ans)))


if __name__ == "__main__":
    solve()
