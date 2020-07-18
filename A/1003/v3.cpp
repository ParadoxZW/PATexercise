/**
 * 迪杰斯特拉算法
 * 邻接表版、O(Vlog(V) + E)版
 * 需要搭配最短距离数组d和最短距离 priority_queue dq
 * 更新dis后push新的节点
 * 取出top u，u.dis和d[u.v]中的值进行对比，d中的值是最新的，
 * 不相等说明这个u已经过期，continue抛弃节点
 * 对相等的情况进行后续处理，如果能优化j.dis, 则新建节点push入dq
 */
#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>
using namespace std;

const int maxl = 0x3fffffff;
const int maxn = 600;

int hr[maxn] = {};     // human resource
int people[maxn] = {}; // maximum number of people one node can gather
int ways[maxn] = {};   // maximum number of path to one node
bool vis[maxn] = {};
int d[600]; // min distance
int nc, nr, src, tar, x, y, x2y;
int tmp; // 保存可能更新的新的距离 tmp = j.len_uv + d[u.v];
int u;    // 取出dq队首

struct Edge {
    int len_uv, v; // 边的长度，所连接的节点
};
vector<Edge> adj[maxn]; // 邻接表
struct cmp {
    bool operator () (int x1, int x2) {
        return d[x1] > d[x2];
    }
};
priority_queue<int, vector<int>, cmp> dq;

int main(void) {
    cin >> nc >> nr >> src >> tar;
    for (int i = 0; i < nc; i++) {
        cin >> hr[i];
    }
    fill(d, d + nc + 10, maxl);
    d[src] = 0;
    dq.push(src);
    for (int i = 0; i < nr; i++) {
        cin >> x >> y;
        cin >> x2y;
        Edge a = {.len_uv = x2y, .v = y}, b = {.len_uv = x2y, .v = x};
        adj[x].push_back(a);
        adj[y].push_back(b);
    }

    // initial
    ways[src] = 1;
    people[src] = hr[src];
    // dijk
    for (int i = 0; i < nc; i++) {
        while(!dq.empty()) {
            u = dq.top();
            dq.pop();
            if (!vis[u]) {
                break;
            }
        }
        if (u == tar) {
            break;
        }
        vis[u] = true;
        for (auto j : adj[u]) {
            if (!vis[j.v]) { // 不处理已经访问过的节点
                tmp = j.len_uv + d[u];
                if (tmp < d[j.v]) { // 优化d[j.v], 更新people和ways
                    d[j.v] = tmp;
                    dq.push(j.v);
                    ways[j.v] = ways[u];
                    people[j.v] = people[u] + hr[j.v];
                } else if (tmp == d[j.v]) { // 更新people和ways
                    ways[j.v] += ways[u];
                    people[j.v] = max(people[u] + hr[j.v], people[j.v]);
                }
            }
        }
    }
    cout << ways[tar] << " " << people[tar] << endl;
    return 0;
}
