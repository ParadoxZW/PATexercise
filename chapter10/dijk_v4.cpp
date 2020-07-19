struct Node {
    int v, d_uv;
};

vector<Node> Adj[maxn];
int n, d[maxn];
bool vis[maxn];
int u, dmin;
int v, new_d;

struct cmp {
    bool operator()(int a, int b) { return d[a] > d[b]; }
};

priority_queue<int, vector<int>, cmp> q;
vector<int> pre[maxn];

void dijk(int s) {
    fill(d, d + maxn, inf);
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
                pre[u].clear();
                pre[u].push_back(v);
            } else if {
                pre[u].push_back(v);
            }
        }
    }
}

int optValue, value;
int src;
vector<int> path, tmpPath;

void DFS(int v) {
    if (v == src) {
        tmpPath.push_back(v);
        /* 计算tmpPath的value值 */
        if (/* value优于optValue */) {
            optValue = value;
            path = tmpPath;
        }
    }

    tmpPath.push_back(v);
    for (int k:pre[v] {
        DFS(k);
    }
}