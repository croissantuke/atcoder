import sys
from bisect import bisect_right

input = sys.stdin.readline


class SmartList:
    def __init__(self, items):
        self.items = sorted(items, key=lambda x: x[0], reverse=True)
        self.count_cum = [0]
        self.value_cum = [0]
        cc = 0
        vc = 0
        for v, k in self.items:
            cc += k
            vc += v * k
            self.count_cum.append(cc)
            self.value_cum.append(vc)
        self.total_count = cc

    def get_value(self, k):
        if k <= 0:
            return 0
        if k >= self.total_count:
            return self.value_cum[-1]
        idx = bisect_right(self.count_cum, k) - 1
        res = self.value_cum[idx]
        rem = k - self.count_cum[idx]
        val, _ = self.items[idx]
        res += val * rem
        return res


def a():
    line = input().split()
    if not line:
        return
    N, C = map(int, line)
    w1 = []
    w2 = []
    w3 = []
    for _ in range(N):
        w, v, k = map(int, input().split())
        if w == 1:
            w1.append((v, k))
        elif w == 2:
            w2.append((v, k))
        else:
            w3.append((v, k))
    l1 = SmartList(w1)
    l2 = SmartList(w2)
    l3 = SmartList(w3)

    def calc_1_2(rem_c):
        if rem_c < 0:
            return -1
        max_k2 = min(l2.total_count, rem_c // 2)
        low = 0
        high = max_k2

        def ev(k2):
            v2 = l2.get_value(k2)
            rem = rem_c - k2 * 2
            v1 = l1.get_value(rem)
            return v1 + v2

        while high - low > 2:
            m1 = low + (high - low) // 3
            m2 = high - (high - low) // 3
            if ev(m1) < ev(m2):
                low = m1
            else:
                high = m2
        return max(ev(i) for i in range(low, high + 1))

    max_k3 = min(l3.total_count, C // 3)
    low = 0
    high = max_k3

    def evtot(k3):
        v3 = l3.get_value(k3)
        rem = C - k3 * 3
        vr = calc_1_2(rem)
        return v3 + vr

    while high - low > 2:
        m1 = low + (high - low) // 3
        m2 = high - (high - low) // 3
        if evtot(m1) < evtot(m2):
            low = m1
        else:
            high = m2
    ans = max(evtot(i) for i in range(low, high + 1))
    print(ans)


if __name__ == "__main__":
    a()
