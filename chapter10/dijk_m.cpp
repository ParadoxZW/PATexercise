const int maxn = 1000;
const int inf = 0x3fffffff;

int n, G[maxn][maxn];
int d[maxn];
bool vis[maxn];
int u, dmin, new_d;

void dijk(int s) {
    fill(d, d+maxn, inf);
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
        for (int v = 0; v < n; v++) {
            new_d = d[u] + G[u][v];
            if (!vis[v] && G[u][v] != inf && new_d < d[v]) {
                d[v] = new_d;
            }
        }
    }
}
