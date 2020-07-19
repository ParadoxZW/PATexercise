struct edge {
    int u, v;
    int cost;
};
edge E[maxn];
bool cmp(edge a, edge b) {
    return a.cost < b.cost;
}
int father[maxn];

int kruskal(int n, int m ){
    int ans = 0, Num_Edge = 0;
    for (int i = 0; i <= n; i++) {
        father[i] = i;
    }
    sort(E, E+m, cmp);
    for (int i = 0; i < m; i++) {
        int faU = findFather(E[i].u);
        int faV = findFather(E[i].v);
        if (faU != faV) {
            father[faU] = faV;
            ans += E[i].cost;
            Num_Edge++;
            if (Num_Edge == n - 1) {
                break;
            }
        }
    }
    if (Num_Edge != n - 1) return -1;
    return ans;
}