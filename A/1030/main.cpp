#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
// #include <mat_print.hpp>
using namespace std;

struct Node {
    int to, len; 
};

const int maxn = 600;
const int inf = 0x3fffffff;

vector<Node> Adj[maxn];
int N, M, S, D;
int d[maxn];
int cost[maxn][maxn];
int u, v, len, cst, tmp;
int vis[maxn];

struct cmp {
    bool operator () (int a, int b) {
        return d[a] > d[b];
    }
};
priority_queue<int, vector<int>, cmp> q;
vector<int> pre[maxn], tmpPath, path;
int optValue, value;

void DFS(int s) {
    if (s == S) {
        tmpPath.push_back(s);
        value = 0;
        for (int i = 0; i < tmpPath.size() - 1; i++) {
            int a, b;
            a = tmpPath[i];
            b = tmpPath[i+1];
            // cout << cost[a][b] << endl;
            value += cost[a][b];
        }
        // cout << value << endl;
        // cout << endl;
        if (value < optValue) {
            optValue = value;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }   
    tmpPath.push_back(s); 
    for (auto j: pre[s]) {
        DFS(j);
    }
    tmpPath.pop_back();
    return;
}

int main(void) {
    cin >> N >> M >> S >> D;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &u, &v, &len, &cst);
        Node to_v = {.to = v, .len = len};
        Node to_u = {.to = u, .len = len};
        cost[u][v] = cost[v][u] = cst;
        Adj[u].push_back(to_v);
        Adj[v].push_back(to_u);
    }
    // cout << cost[1][0] << endl;
    // cout << cost[3][1] << endl;
    fill(d, d + N + 10, inf);
    d[S] = 0;
    vis[S] = true;
    q.push(S);
    for (int i = 0; i < N; i++) {
        while(!q.empty()){
            u = q.top();
            q.pop();
            if (!vis[u]) {
                vis[u] = true;
                break;
            }
        }
        if (u == D)
            break;
        for(auto j:Adj[u]) {
            v = j.to;
            len = j.len;
            if (!vis[v]) {
                if (len + d[u] < d[v]) {
                    d[v] = len + d[u];
                    q.push(v);
                    pre[v].clear();
                    pre[v].push_back(u);
                } else if (len + d[u] == d[v]) {
                    pre[v].push_back(u);
                }
            }            
        }
    }
    optValue = inf;
    DFS(D);
    int k = path.size() - 1;
    cout << path[k--];
    for (;k >= 0; k--) {
        printf(" %d", path[k]);
    }
    printf(" %d", d[D]);
    printf(" %d\n", optValue);

    return 0;
}