import sys

# 入力の読み込み高速化
input = sys.stdin.readline


def solve():
    # 入力
    # N: 人数, Q: クエリ数
    line1 = input().split()
    if not line1:
        return
    N, Q = int(line1[0]), int(line1[1])

    # A: 遷移先 (1-indexedにするため先頭に0を追加)
    A_list = list(map(int, input().split()))
    A = [0] + A_list

    # ダブリングの準備
    # MAX_LOG: 2^k <= 10^9 となる最大の k は 29 なので 30 程度あれば十分
    MAX_LOG = 30

    # next_pos[k][i]: 頂点 i から 2^k 回進んだ位置
    # total_val[k][i]: 頂点 i から 2^k 回進む間の番号の総和
    next_pos = [[0] * (N + 1) for _ in range(MAX_LOG)]
    total_val = [[0] * (N + 1) for _ in range(MAX_LOG)]

    # 初期値 (k=0, つまり 2^0 = 1 回分の移動)
    for i in range(1, N + 1):
        next_pos[0][i] = A[i]
        total_val[0][i] = i  # 1ステップ目は「現在持っている人 i」の水が入る

    # ダブリングの前計算
    for k in range(MAX_LOG - 1):
        for i in range(1, N + 1):
            # 2^(k+1) 回の移動 = 2^k 回移動して、そこからさらに 2^k 回移動
            half_pos = next_pos[k][i]

            next_pos[k + 1][i] = next_pos[k][half_pos]
            total_val[k + 1][i] = total_val[k][i] + total_val[k][half_pos]

    # クエリ処理
    for _ in range(Q):
        line = list(map(int, input().split()))
        T = line[0]
        B = line[1]

        current_pos = B
        ans = 0

        # T をビットごとに見ていく
        # 例: T=6 (binary 110) なら、k=2(4) と k=1(2) の部分を足す
        for k in range(MAX_LOG):
            # k ビット目が立っているか確認 (T & (1 << k))
            if (T >> k) & 1:
                ans += total_val[k][current_pos]
                current_pos = next_pos[k][current_pos]

        print(ans)


if __name__ == "__main__":
    solve()
