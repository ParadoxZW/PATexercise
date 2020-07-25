stack<int> topOrder;

bool topoSort() {
    int num = 0;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        // printf("%d\n", u);
        q.pop();
        topOrder.push(u);
        for (auto j : G[u]) {
            int v = j.v;
            int w = j.w;
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
            if(ve[u] + w > ve[v]) {
                ve[v] = ve[u] + w;
            }
        }
        num++;
    }
    if (num == n)
        return true;
    return false;
}

int CriticalPath() {
    memset(ve, 0, sizeof(ve));
    if(topoSort() == false) {
        return -1;
    }
    fill(vl, vl+n, ve[n-1]);
    while(!topOrder.empty()) {
        int u = topOrder.top();
        topOrder.pop();
        for(auto j:G[u]) {
            int v = j.v;
            int w = j.w;
            if(vl[v] - w < vl[u]) {
                vl[u] = vl[v] - w;
            }
        }
    }

    for(int u = 0; u < n; u++) {
        for (auto j: G[u]) {
            int v = j.v;
            int w = j.w;
            int e = ve[u], l = vl[v] - w;
            if(e == l) {
                printf("%d->%d\n", u, v);
            }
        }
    }

    return ve[n-1];
}