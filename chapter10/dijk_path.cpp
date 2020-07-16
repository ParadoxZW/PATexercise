struct Node {
    int v, d_uv;
};

vector<Node> Adj[maxn];
int n, d[maxn];
bool vis[maxn];
int u, dmin;
int v, new_d;
int pre[maxn];

struct cmp {
    bool operator()(int a, int b) { return d[a] > d[b]; }
};

priority_queue<int, vector<int>, cmp> q;

void dijk(int s) {
    fill(d, d + maxn, inf);
    for (int i = 0; i < n; i++) {
        pre[i] = i;
    }
    d[s] = 0;
    q.push(s);
    for (int i = 0; i < n; i++) {
        u = -1;
        while (!q.empty()) {
            u = q.top();
            q.pop();
            if (!vis[u])
                break;
        }
        if (u == -1)
            return;

        vis[u] = true;
        for (auto vx : Adj[u]) {
            v = vx.v;
            new_d = vx.d_uv + d[u];
            if (!vis[v] && new_d < d[v]) {
                d[v] = new_d;
                q.push(v);
                pre[v] = u;
            }
        }
    }
}


void DFS(int s, int v) {
    if (v == s) {
        printf("%d\n", s);
        return;
    }
    DFS(s, pre[v]);
    printf("%d\n", v);
}