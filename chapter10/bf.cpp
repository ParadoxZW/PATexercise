bool Bellman(int s) {
    fill(d, d+maxn, inf);
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        bool flag = true;
        for (int u = 0; u < n; u++) {
            for (auto j:Adj[u]) {
                int v = j.v;
                int dis = j.d_uv;
                if (d[u] + dis < d[v]) {
                    d[v] = d[u] + dis;
                    flag = false;
                }
            }
        }
        if (flag) { // 已达到最优
            return true;
        }
    }

    return false;
}
