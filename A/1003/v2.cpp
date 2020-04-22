/**
 * 迪杰斯特拉算法
 * 邻接表版、O(Vlog(V) + E)版
 * 需要搭配最短距离数组d和最短距离 priority_queue dq
 * 更新dis后push新的节点
 * 取出top u，u.dis和d[u.v]中的值进行对比，d中的值是最新的，
 * 不相等说明这个u已经过期，continue抛弃节点
 * 对相等的情况进行后续处理，如果能优化j.dis, 则新建节点push入dq
 */
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;

int hr[600] = {};  // human resource
int people[600] = {};  // maximum number of people one node can gather
int ways[600] = {};  // maximum number of path to one node
// int arc[600][600] = {};
bool vis[600] = {};
const int maxl = 0x3fffffff;
// vector<int> back[600];
int nc, nr, src, tar, x, y, len_;

struct Edge {
    int len, v; // 边的长度，所连接的节点
};
vector<Edge> adj[600];  // 邻接表

// struct cmp {
//     bool operator () (int x1, int x2) {
//         return d[x1] > d[x2];
//     }
// };

// dijk所需的用以维护源到点的最短距离的数据结构
int d[600];  // min distance
struct PE {  // priority element of min distance
    int v, dis;
    friend bool operator < (PE d1, PE d2) {
        return d1.dis > d2.dis;
    }
};
priority_queue<PE> dq;


int main(void)
{
    cin >> nc >> nr >> src >> tar;
    for (int i=0; i<nc; i++){
        cin >> hr[i];
        vis[i] = false;
        d[i] = (i==src?0:maxl);
        PE e = {.v=i, .dis=d[i]};
        dq.push(e);
    }
    for (int i=0; i<nr; i++){
        cin >> x >> y;
        cin >> len_;
        Edge a = {.len=len_, .v=y}, b = {.len=len_, .v=x};
        adj[x].push_back(a);
        adj[y].push_back(b);
    }

    // initial
    int tmp;  // 保存可能更新的新的距离 tmp = j.len + d[u.v]; 
    PE u;     // 取出dq队首
    ways[src] = 1;
    people[src] = hr[src];
    // dijk
    for (int i=0; i<nc; i++){
        // std::cout << u.idx << std::endl;
        u = dq.top();
        dq.pop();
        if (u.v == tar){
            break;
        }
        if (u.dis != d[u.v]) continue;  // dq中的无效节点，因为相应的dis已经更新
        vis[u.v] = true;
        for(auto j: adj[u.v]){
            if(!vis[j.v]){  // 不处理已经访问过的节点
                tmp = j.len + d[u.v]; 
                if (tmp < d[j.v]){  // 优化d[j.v], 更新people和ways
                    d[j.v] = tmp;
                    PE id_new = {.v=j.v, .dis=tmp};
                    dq.push(id_new);
                    ways[j.v] = ways[u.v];
                    people[j.v] = people[u.v] + hr[j.v];
                }else if (tmp == d[j.v]){  // 更新people和ways
                    ways[j.v] += ways[u.v];
                    people[j.v] = max(people[u.v]+hr[j.v], people[j.v]);
                }
            }
        }

    }
    cout << ways[tar] <<" "<< people[tar] << endl;
    return 0;
}
