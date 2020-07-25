vector<int> G[maxn];
int n, m, inDegree[maxn];

bool topoSort() {
    int num = 0;
    queue<int> q;
    for(int i=0;i<n;i++){
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int u = q.front();
        // printf("%d\n", u);
        q.pop();
        for(int v:G[u]) {
            inDegree[v]--;
            if(inDegree[v] == 0) {
                q.push(v);
            }
        }
        num++;
    }
    if(num==n) return true;
    return false;
}