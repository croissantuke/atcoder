import sys

data = map(int, sys.stdin.read().split())
Q = next(data)
vol = 0
play = 0
out = []
for op in data:
    if op == 1:
        vol += 1
    elif op == 2:
        vol -= vol > 0
    elif op == 3:
        play ^= 1
    if play and vol >= 3:
        out.append("Yes")
    else:
        out.append("No")
print("\n".join(out))
