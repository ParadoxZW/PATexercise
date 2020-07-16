for (auto vx : Adj[u]) {
    v = vx.v;
    new_d = vx.d_uv + d[u];
    new_c = c[u] + cost[u][v];
    if (!vis[v]) {
        if (new_d < d[v]) {
            d[v] = new_d;
            c[v] = new_c;
            q.push(v);
        } else if (new_d == d[v] && new_c < c[v]) {
            c[v] = new_c;
            q.push(v);
        }
    }
}