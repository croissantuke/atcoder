import sys


def solve():
    # 入力をすべて読み込む
    data = sys.stdin.read().split()
    n = int(data[0])

    # 2つ目以降が数列A
    # data[1:] を使うとメモリコピーが走るので、イテレータで回すかindexアクセスが良いが、
    # Pythonのリスト操作ならこれくらいは許容範囲
    a = data[1:]

    # これがスタック（最初は空っぽ）
    stack = []

    for x in a:
        # 1. とりあえず積む
        stack.append(x)

        # 2. 4つ以上溜まっているか確認
        if len(stack) >= 4:
            # 3. 直近の4つが同じ数字か確認
            # stack[-1] は一番最後に入れたもの、stack[-2]はその一つ前...
            if stack[-1] == stack[-2] == stack[-3] == stack[-4]:
                # 4. 同じなら4回popする（削除する）
                # del stack[-4:] が高速でおすすめ
                del stack[-4:]

    # 最終的にスタックに残った要素数が答え
    print(len(stack))


if __name__ == "__main__":
    solve()
