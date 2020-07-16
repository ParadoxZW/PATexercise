for (auto vx : Adj[u]) {
    v = vx.v;
    new_d = vx.d_uv + d[u];
    new_w = w[u] + weight[v];
    if (!vis[v]) {
        if (new_d < d[v]) {
            d[v] = new_d;
            w[v] = new_w;
            q.push(v);
        } else if (new_d == d[v] && new_w > w[v]) {
            c[w] = new_w;
            q.push(v);
        }
    }
}