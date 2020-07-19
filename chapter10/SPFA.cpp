int num[maxn];  // 记录顶点入队次数
bool inq[maxn]; // 顶点是否在队列中
queue<int> Q;

bool SPFA(int s) {
    fill(d, d+maxn, inf);
    Q.push(s);
    d[s] = 0
    inq[s] = true;

    while(!Q.empty()) {
        int u = Q.front();
        Q.pop();
        inq[u] = false;

        for (auto j: Adj[u]) {
            int v = j.v;
            int dis = j.d_uv;
            if (d[u] + dis < d[v]) {
                d[v] = d[u] + dis;
                if (!inq[v]) {
                    Q.push(v);
                    inq[v] = true;
                    num[v]++;
                    if (num[v] >= n)
                        return false;
                }
            }
        }
    }
    return true;
}