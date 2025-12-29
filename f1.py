import sys

# 再帰上限を引き上げ
sys.setrecursionlimit(300000)
input = sys.stdin.readline


def solve():
    N = int(input())
    adj = [[] for _ in range(N)]
    for _ in range(N - 1):
        u, v = map(int, input().split())
        adj[u].append(v)
        adj[v].append(u)

    # 根を0とするDFSで、深さ・親・部分木サイズを計算
    depth = [0] * N
    parent = [[-1] * 20 for _ in range(N)]
    subtree_size = [1] * N

    # 帰りがけ順でサイズを計算するためのスタック処理等は少し複雑になるため
    # ここでは単純な再帰DFSを採用（制約 N=2*10^5 ならPyPyで通る）
    # BFSや非再帰DFSで書くのが安全だが、可読性重視で記述

    stack = [0]
    visited = [False] * N
    visited[0] = True
    order = []  # 行きがけ順

    # Pre-process using explicit stack to avoid recursion depth issues slightly
    # and to compute subtree sizes in reverse order
    while stack:
        u = stack.pop()
        order.append(u)
        for v in adj[u]:
            if not visited[v]:
                visited[v] = True
                depth[v] = depth[u] + 1
                parent[v][0] = u
                stack.append(v)

    # Calculate subtree sizes in reverse topological order
    for i in range(N - 1, 0, -1):
        child = order[i]
        p = parent[child][0]
        if p != -1:
            subtree_size[p] += subtree_size[child]

    # Doubling for LCA
    for k in range(1, 20):
        for i in range(N):
            if parent[i][k - 1] != -1:
                parent[i][k] = parent[parent[i][k - 1]][k - 1]
            else:
                parent[i][k] = -1

    def get_lca(u, v):
        if depth[u] < depth[v]:
            u, v = v, u

        # Lift u to the same depth as v
        for k in range(19, -1, -1):
            if ((depth[u] - depth[v]) >> k) & 1:
                u = parent[u][k]

        if u == v:
            return u

        for k in range(19, -1, -1):
            if parent[u][k] != parent[v][k]:
                u = parent[u][k]
                v = parent[v][k]

        return parent[u][0]

    def get_dist(u, v):
        lca = get_lca(u, v)
        return depth[u] + depth[v] - 2 * depth[lca]

    # 指定した深さの祖先を取得（0の子を取得するために使用）
    def get_ancestor_at_depth(u, d):
        target_depth = d
        if depth[u] < target_depth:
            return -1  # Should not happen in this logic
        diff = depth[u] - target_depth
        for k in range(19, -1, -1):
            if (diff >> k) & 1:
                u = parent[u][k]
        return u

    # パス {0, ..., k} の両端点が u, v のとき、条件を満たす (i, j) の数を計算
    # 根は常に 0 であることを利用
    def calc_count(u, v):
        # Case 1: パスが一点 0 のみ
        if u == 0 and v == 0:
            total_pairs = N * (N + 1) // 2
            invalid_pairs = 0
            for child in adj[0]:
                if depth[child] > depth[0]:  # 0の子のみ（親方向除外）
                    s = subtree_size[child]
                    invalid_pairs += s * (s + 1) // 2
            return total_pairs - invalid_pairs

        # Case 2: パスが 0 と、ある部分木内の頂点 u を結ぶ (v=0)
        elif v == 0:
            # u は 0 ではない
            # u の部分木サイズ × (全体 - uが属する0の直下部分木のサイズ)
            child_of_root = get_ancestor_at_depth(u, 1)
            size_u = subtree_size[u]
            size_rest = N - subtree_size[child_of_root]
            return size_u * size_rest

        elif u == 0:
            # Symmetric to above
            child_of_root = get_ancestor_at_depth(v, 1)
            size_v = subtree_size[v]
            size_rest = N - subtree_size[child_of_root]
            return size_v * size_rest

        # Case 3: パスが u ... 0 ... v (u, v は 0 の異なる部分木に属する)
        else:
            return subtree_size[u] * subtree_size[v]

    # Main Logic
    total_ans = 0

    # k=0 のとき (MEX > 0 つまり 0 を含むパス)
    curr_u, curr_v = 0, 0
    total_ans += calc_count(0, 0)

    for k in range(1, N):
        # 頂点 k を現在のパスに追加できるか判定

        # k が既にパス上にあるか？ dist(u, k) + dist(k, v) == dist(u, v)
        d_uv = get_dist(curr_u, curr_v)
        d_uk = get_dist(curr_u, k)
        d_kv = get_dist(k, curr_v)

        if d_uk + d_kv == d_uv:
            # k は既にパス上にある -> 端点更新なし
            pass

        # k が u 側の延長線上にあるか？ dist(k, v) == dist(k, u) + dist(u, v)
        elif d_kv == d_uk + d_uv:
            curr_u = k

        # k が v 側の延長線上にあるか？ dist(u, k) == dist(u, v) + dist(v, k)
        elif d_uk == d_uv + d_kv:
            curr_v = k

        else:
            # 一直線にならない -> これ以上 MEX を大きくできない
            break

        # 更新された端点でカウントを加算
        total_ans += calc_count(curr_u, curr_v)

    print(total_ans)


if __name__ == "__main__":
    solve()
