import sys


def solve():
    data = sys.stdin.read().split()
    n = int(data[0])
    m = int(data[1])
    s = data[2]
    t = data[3]

    ans = 10**18

    for i in range(n - m + 1):
        cnt = 0
        for j in range(m):
            si = int(s[i + j])
            tj = int(t[j])
            cnt += (si - tj + 10) % 10

        if cnt < ans:
            ans = cnt

    print(ans)


if __name__ == "__main__":
    solve()
