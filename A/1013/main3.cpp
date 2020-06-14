#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

const int N = 1111;
vector<int> G[N];
bool vis[N];

int cP;

void dfs(int v) {
    if (v == cP) return;
    vis[v] = true;
    for(auto i:G[v]){
        if(!vis[i]){
            dfs(i);
        }
    }
}

int n, m, k;
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int query = 0; query < k; query++) {
        cin >> cP;
        memset(vis, false, n+2);
        int ll = G[query].size();
        if (n > 5 && m - ll >= (n - 2) * (n - 3) / 2 + 1) {
            cout << 0 << endl;
            continue;
        }
        int block = 0;
        for (int i = 1; i <= n; i++) {
            if(i != cP && !vis[i]){
                dfs(i);
                block++;
            }
        }
        cout << block - 1 << endl;
    }
}
