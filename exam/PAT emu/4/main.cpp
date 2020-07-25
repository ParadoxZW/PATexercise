// #include <bits/stdc++.h>
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
const int maxn = 300;
const int inf = 0x3fffffff;

map<string, int> name2id;
string id2name[maxn];
int N, K;
int idx;
string nm;
char nms[10];
int hpn;
int hp[maxn];
int pre[maxn];

struct Node {
    int to, len;
};

vector<Node> Adj[maxn];
string nm1, nm2;
int ct;
int u, v;
int d[maxn];
bool vis[maxn];
int hpsum[maxn];
int hop[maxn];
int num[maxn];
int tar;


struct cmp{
    bool operator() (int a, int b) {
        return d[a] > d[b];
    }
};

priority_queue<int, vector<int>, cmp > pq;

void DFS(int k) {
    if (k == 0){
        cout << id2name[k];
        return;
    }
    DFS(pre[k]);
    cout << "->" << id2name[k];
}

int main() {
#ifdef LOCAL
    freopen("./4/1.txt", "r", stdin);
#endif
    // cin >> N >> K >> nm;
    scanf("%d %d %s", &N, &K, nms);
    // string nm;
    nm = nms;
    name2id[nm] = 0;
    id2name[idx++] = nm;
    hp[0] = 0;
    for (; idx < N; idx++) {
        scanf("%s %d", nms, &hpn);
        nm = nms;
        name2id[nm] = idx;
        id2name[idx] = nm;
        // cout << id2name[idx] << endl;
        hp[idx] = hpn;
    }
    for (int i = 0; i < K; i++) {
        cin >> nm1 >> nm2 >> ct;
        u = name2id[nm1];
        v = name2id[nm2];
        // cout << u << ' ' << v << endl;
        Node to_v = {.to = v, .len=ct};
        Node to_u = {.to = u, .len=ct};
        Adj[u].push_back(to_v);
        Adj[v].push_back(to_u);
    }
    // cout << "ok" << endl;
    fill(d, d+N+10, inf);
    d[0] = 0;
    // vis[0] = true;
    pq.push(0);
    hop[0] = 0;
    hpsum[0] = 0;
    pre[0] = 0;
    num[0] = 1;
    // cout << Adj[0].size() << endl;
        // for(auto j:Adj[0]) {
        //     cout << j.to << endl;
        // }
    for (int i = 0; i < N; i++) {
        // cout << vis[0] << 'x' << endl;
        while(true) {
            u = pq.top();
            // cout << u << endl;
            pq.pop();
            if(!vis[u]) {
                break;
            }
        }
        vis[u] = true;
        for(auto j:Adj[u]) {
            v = j.to;
            ct = j.len;
            if (!vis[v]) {
                // cout << v << endl;
                if(d[v] > d[u] + ct) {
                    d[v] = d[u] + ct;
                    hop[v] = hop[u] + 1;
                    hpsum[v] = hpsum[u] + hp[v];
                    pre[v] = u;
                    num[v] = num[u];
                    pq.push(v);
                } else if (d[v] == d[u] + ct) {
                    if (hpsum[v] < hpsum[u] + hp[v]) {
                        hop[v] = hop[u] + 1;
                        hpsum[v] = hpsum[u] + hp[v];
                        pre[v] = u;
                    } else if (hpsum[v] == hpsum[u] + hp[v]) {
                        if (hop[v] > hop[u] + 1) {
                            hop[v] = hop[u] + 1;
                            pre[v] = u;
                        }
                    }
                    num[v]++;
                }
            }
        }
    }
    tar = name2id["ROM"];
    printf("%d %d %d %d\n", num[tar], d[tar], hpsum[tar], hpsum[tar]/hop[tar]);
    DFS(tar);
    cout << endl;

    return 0;
}