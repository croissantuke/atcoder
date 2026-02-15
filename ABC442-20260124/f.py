import sys


def solve():
    input = sys.stdin.read
    data = input().split()
    N = int(data[0])
    S = data[1:]
    dp = [0] * (N + 1)
    INF = 10**18
    for s in S:
        current_cost = s.count(".")
        row_costs = [0] * (N + 1)
        row_costs[0] = current_cost
        for j in range(N):
            if s[j] == "#":
                current_cost += 1
            else:
                current_cost -= 1
            row_costs[j + 1] = current_cost
        new_dp = [0] * (N + 1)
        min_val = INF
        for j in range(N, -1, -1):
            if dp[j] < min_val:
                min_val = dp[j]
            new_dp[j] = row_costs[j] + min_val
        dp = new_dp

    print(min(dp))


if __name__ == "__main__":
    solve()
