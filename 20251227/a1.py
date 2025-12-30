import sys


def solve():
    line = sys.stdin.read().split()
    if not line:
        return
    d = int(line[0])
    f = int(line[1])
    rem = (d - f) % 7
    ans = 7 - rem
    print(ans)


if __name__ == "__main__":
    solve()
