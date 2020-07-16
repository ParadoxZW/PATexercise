for (auto vx : Adj[u]) {
    v = vx.v;
    new_d = vx.d_uv + d[u];
    if (!vis[v]) {
        if (new_d < d[v]) {
            d[v] = new_d;
            num[v] = num[u];
            q.push(v);
        } else if (new_d == d[v] && new_c < c[v]) {
            num[v] += num[u];
        }
    }
}