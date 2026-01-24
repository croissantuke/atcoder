import sys
from bisect import bisect_right

# 入力を高速に読み込む
input = sys.stdin.readline


class SmartList:
    """
    重さごとのアイテムを管理し、上位k個の合計価値を高速に計算するクラス
    """

    def __init__(self, items):
        # items: (value, count) のリスト
        # 価値が高い順にソート
        self.items = sorted(items, key=lambda x: x[0], reverse=True)

        # 累積和の構築
        self.count_cum = [0]
        self.value_cum = [0]

        curr_count = 0
        curr_value = 0

        for v, k in self.items:
            curr_count += k
            curr_value += v * k
            self.count_cum.append(curr_count)
            self.value_cum.append(curr_value)

        self.total_count = curr_count

    def get_value(self, k):
        """上位k個のアイテムの合計価値を返す"""
        if k <= 0:
            return 0
        if k >= self.total_count:
            return self.value_cum[-1]

        # どのブロックまで完全に含まれるか二分探索
        idx = bisect_right(self.count_cum, k) - 1

        # 完全に含まれる部分の価値
        res = self.value_cum[idx]

        # 端数部分の計算
        remain = k - self.count_cum[idx]
        val, _ = self.items[idx]
        res += val * remain

        return res


def solve():
    # 入力受け取り
    try:
        line1 = input().split()
        if not line1:
            return  # End of input
        N, C = map(int, line1)

        w1_items = []
        w2_items = []
        w3_items = []

        for _ in range(N):
            w, v, k = map(int, input().split())
            if w == 1:
                w1_items.append((v, k))
            elif w == 2:
                w2_items.append((v, k))
            else:  # w == 3
                w3_items.append((v, k))

    except ValueError:
        return

    # 各重さの管理クラスを作成
    list1 = SmartList(w1_items)
    list2 = SmartList(w2_items)
    list3 = SmartList(w3_items)

    # ---------------------------------------------------------
    # 容量 rem_c に対して、重さ1と2を使って得られる最大価値を返す関数
    # （重さ2の使用個数に対して凸性があるので三分探索する）
    # ---------------------------------------------------------
    def calc_1_2(rem_c):
        if rem_c < 0:
            return -1

        # 重さ2を使える最大個数
        max_k2 = min(list2.total_count, rem_c // 2)

        # 三分探索で最適な重さ2の個数(k2)を探す
        low = 0
        high = max_k2

        # 評価関数: 重さ2をk2個使ったときの (W2の価値 + W1の価値)
        def eval_func(k2):
            val2 = list2.get_value(k2)
            rem_for_1 = rem_c - k2 * 2
            # 重さ1は詰め込めるだけ詰めるのが最適
            val1 = list1.get_value(rem_for_1)
            return val1 + val2

        # 整数三分探索
        while high - low > 2:
            m1 = low + (high - low) // 3
            m2 = high - (high - low) // 3
            if eval_func(m1) < eval_func(m2):
                low = m1
            else:
                high = m2

        # 狭まった範囲を全探索
        return max(eval_func(i) for i in range(low, high + 1))

    # ---------------------------------------------------------
    # 全体の容量 C に対して、重さ3の使用個数を三分探索する
    # ---------------------------------------------------------

    # 重さ3を使える最大個数
    max_k3 = min(list3.total_count, C // 3)

    low = 0
    high = max_k3

    def eval_total(k3):
        val3 = list3.get_value(k3)
        rem_c = C - k3 * 3
        val_rest = calc_1_2(rem_c)
        return val3 + val_rest

    while high - low > 2:
        m1 = low + (high - low) // 3
        m2 = high - (high - low) // 3
        if eval_total(m1) < eval_total(m2):
            low = m1
        else:
            high = m2

    ans = max(eval_total(i) for i in range(low, high + 1))
    print(ans)


if __name__ == "__main__":
    solve()
