#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<cstdlib>
using namespace std;
const int maxn = 110;

vector<int> G[maxn];
int h[maxn]; // 每层节点所在层号
int N, M, maxh, idx, idy, k, l;
int ans[maxn] = {0};

void BFS() { 
    queue<int> Q;
    Q.push(1);
    while(!Q.empty()){
        int id = Q.front();
        Q.pop();
        if (G[id].empty()) {
            ans[h[id]]++;
        }else{
            l = h[id] + 1;
            maxh = max(l, maxh);
            for(auto i: G[id]) {
                h[i] = l;
                Q.push(i);
            }
        }
    }
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        cin >> idx >> k;
        // G[idx]
        for (int j = 0; j < k; j++) {
            cin >> idy;
            G[idx].push_back(idy);
        }
    }
    BFS();
    for (int i = 0; i <= maxh; i++) {
        printf("%d", ans[i]);
        if (i != maxh) {
            printf(" ");
        }
    }
    return 0;
}