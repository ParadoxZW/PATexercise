#include <bits/stdc++.h>
using namespace std;

const int maxn=600;

// vector<int> Adj[maxn];
bool G[maxn][maxn];
int N, R, K, M;
int a,b;

set<int> s;
int x[maxn];
bool flag;

bool judge(vector<int> p[]) {
    for (int j:s) {
        // cout << j << endl;
        for (int u = 0; u < p[j].size(); u++) {
            for (int v = u + 1; u < p[j].size(); u++) {
                // cout << p[j][v] << " " << p[j][u] << " " << G[p[j][v]][p[j][u]] << endl;
                if (G[p[j][v]][p[j][u]]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
#ifdef LOCAL
    freopen("./1.txt", "r", stdin);
#endif
    cin >> N >> R>> K;
    for (int i = 0; i < R; i++) {
        scanf("%d %d", &a, &b);
        G[a][b] = G[b][a] = true;
    }
    // cout << G[6][3] << endl;
    cin >> M;
    int cc = 0;
    for (int i = 0; i < M; i++) {
        s.clear();
        cc = 0;
        vector<int> p[maxn];
        for (int k = 1; k <= N; k++) {
            scanf("%d", &x[k]);
            s.insert(x[k]);
            p[x[k]].push_back(k);
        }
        if (s.size() > K) {
            printf("Error: Too many species.\n");
        } else if (s.size() <K) {
            printf("Error: Too few species.\n");
        } else{
            if(judge(p)){
                printf("Yes\n");
            }else{
                printf("No\n");
            }
            
        }
    }

    return 0;
}