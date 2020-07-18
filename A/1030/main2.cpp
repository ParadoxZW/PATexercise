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

const int maxn = 600;
const int inf = 0x3fffffff;

struct Node {
    int to, len;
};

vector<Node> Adj[maxn];
int d[maxn], num[maxn];
int cost[maxn][maxn];
int N, M, S, D;
int u, v, tmp, cst, len;
queue<int> q;
vector<int> pre[maxn], tmpPath, path;
bool inq[maxn];
int optValue, value;

void DFS(int s) {
    if (s == S) {
        tmpPath.push_back(s);
        value = 0;
        for (int i = 0; i < tmpPath.size() - 1; i++) {
            int a = tmpPath[i];
            int b = tmpPath[i+1];
            value += cost[a][b];
        }
        // cout << value << endl;
        if (value < optValue) {
            optValue = value;
            path = tmpPath;
        }
        tmpPath.pop_back();
        return;
    }
    tmpPath.push_back(s);
    for(int j:pre[s]) {
        DFS(j);
    }
    tmpPath.pop_back();
    return;
}

bool bellman(int S) {
    fill(d, d + N + 10, inf);
    d[S] = 0;
    q.push(S);
    inq[S] = true;
    while (!q.empty()) {
        u = q.front();
        q.pop();
        inq[u] = false;
        // cout << u << endl;

        for (auto j : Adj[u]) {
            v = j.to;
            len = j.len;
            if (len + d[u] < d[v]) {
                d[v] = len + d[u];
                if (!inq[v]) {
                    inq[v] = true;
                    q.push(v);
                    num[v]++;
                    if (num[v] == N)
                        return true;
                }
                pre[v].clear();
                pre[v].push_back(u);
            } else if (len + d[u] == d[v]) {
                pre[v].push_back(u);
            }
        }
    }
    return false;
}

int main(void) {
    cin >> N >> M >> S >> D;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d %d", &u, &v, &len, &cst);
        Node to_v = {.to = v, .len = len};
        Node to_u = {.to = u, .len = len};
        Adj[u].push_back(to_v);
        Adj[v].push_back(to_u);
        cost[u][v] = cost[v][u] = cst;
    }
    bellman(S);
    // cout << pre[D].size() << endl;
    optValue = inf;
    DFS(D);
    int k = path.size() - 1;
    cout << path[k--];
    for (; k >= 0; k--) {
        printf(" %d", path[k]);
    }
    printf(" %d", d[D]);
    printf(" %d\n", optValue);
    return 0;
}