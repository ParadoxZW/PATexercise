struct Node {
    int v, d_uv;
};

vector<Node> Adj[maxn];
int n, d[maxn];
bool vis[maxn];
int u, dmin;
int v, new_d;

void dijk(int s) { 
    fill(d, d + maxn, inf); 
    d[s] = 0;
    for (int i = 0; i < n; i++) {
        u = -1, dmin = inf;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < dmin) {
                u = j;
                dmin = d[j];
            }
        }

        if (u == -1) return;
        vis[u] = true;
        for (auto vx:Adj[u]) {
            v = vx.v;
            new_d = vx.d_uv + d[u];
            if (!vis[v] && new_d < d[v]) {
                d[v] = new_d;
            }
        }
    }
}