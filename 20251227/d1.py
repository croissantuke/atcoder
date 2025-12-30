import sys


def solve():
    # 高速な入力読み込み
    input_data = sys.stdin.read().split()
    if not input_data:
        return

    iterator = iter(input_data)
    N = int(next(iterator))

    # イテレータを使ってA, B, Cを順番に取得
    # メモリ効率と速度のためにリスト内包表記を使用
    A = [int(next(iterator)) for _ in range(N)]
    B = [int(next(iterator)) for _ in range(N)]
    C = [int(next(iterator)) for _ in range(N)]

    # DPの初期化
    # 最初のブロック(index 0)は必ず「頭」でなければならない
    # 胴や尾がいきなり始まることは制約(x >= 1)により不可なので、
    # 初期値として非常に小さい値(-infinity)を入れておく
    h = A[0]
    b = -float("inf")
    t = -float("inf")

    # 2番目のブロックから最後までループ
    for i in range(1, N):
        a_val = A[i]
        b_val = B[i]
        c_val = C[i]

        # 同時更新（Pythonのタプルアンパックを使うと一時変数が不要で便利）
        # 右辺の h, b, t はすべて「更新前（i-1番目まで）」の値
        h, b, t = (
            h + a_val,  # 頭はずっと頭のまま
            max(h, b) + b_val,  # 胴は「頭から変化」か「胴の継続」
            max(b, t) + c_val,  # 尾は「胴から変化」か「尾の継続」
        )

    # 最終的な答えは、最後まで見たときの「尾」の状態の最大値
    print(t)


if __name__ == "__main__":
    solve()
