import sys


def solve():
    it = iter(sys.stdin.read().split())
    n = int(next(it))
    m = int(next(it))
    deg = [0] * (n + 1)
    for _ in range(m):
        u = int(next(it))
        v = int(next(it))
        deg[u] += 1
        deg[v] += 1
    res = [
        (0 if (c := n - 1 - deg[i]) < 3 else c * (c - 1) * (c - 2) // 6)
        for i in range(1, n + 1)
    ]
    print(*res)


if __name__ == "__main__":
    solve()
