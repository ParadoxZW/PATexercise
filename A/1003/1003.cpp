/**
 * 迪杰斯特拉算法
 * 用arc保存图，d保存到源最短距离，vis记录已经计算出d的点
 * 找到目的地即可以停止dijk
 * 用ways和people分别处理每个已访问点的路径数和召集人数情况，随着dijk算法的推进可前馈计算
 * 为了处理多路径可能，对不能优化d，但是取到相等的情况也要单独处理
 *
 * 注意循环内变量值的重置
 * TODO: 邻接表版、O(Vlog(V) + E)版
 */
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <utility>
#include <vector>
#define max(x,y) (x)>=(y)?(x):(y)

using namespace std;
int p[600] = {};
int people[600] = {};
int arc[600][600] = {};
bool vis[600] = {};
bool vis2[600] = {};
int d[600];
int ways[600] = {};
const int maxl = 0x3fffffff;
// vector<int> back[600];
int nc, nr, src, tar, x, y;

// int count(int t){
//     // cout << t << endl;
//     if (vis2[t]) return 0;
//     if (t == src){
//             vis2[t] = true;
//             return p[t];
//     }
//     int s = 0;
//     for(auto p: back[t]){
//         s += count(p);
//     }
//     vis2[t] = true;
//     return s + p[t];
// }
int main(void)
{
    cin >> nc >> nr >> src >> tar;
    for (int i=0; i<nc; i++){
        cin >> p[i];
        vis[i] = false;
        vis2[i] = false;
        d[i] = maxl;
        for (int j=0; j<nc; j++){
            arc[i][j] = maxl;
        }
        // ways[i] = 0;
    }
    for (int i=0; i<nr; i++){
        cin >> x >> y;
        cin >> arc[x][y];
        arc[y][x] = arc[x][y];
    }
    int u = src, fn, fi, tmp;
    d[src] = 0;
    ways[src] = 1;
    people[src] = p[src];
    for (int i=0; i<nc; i++){
        fn = maxl;
        // cout << u << " "<< people[u] << endl;
        vis[u] = true;
        for (int j=0; j<nc; j++){
            if(!vis[j]){
                tmp = arc[u][j] + d[u];
                // cout << u << " " << j << " " << tmp << endl;
                if (tmp < d[j]){
                    d[j] = tmp;
                    ways[j] = ways[u];
                    people[j] = people[u] + p[j];
                    // back[j].clear();
                    // back[j].push_back(u);
                    // cout << "<" << people[j] << endl;
                    // if (j == tar){
                    //     ans1++;
                    // }
                }else if (tmp == d[j]){
                    ways[j] += ways[u];
                    people[j] = max(people[u]+p[j], people[j]);
                    // back[j].push_back(u);
                    // cout << "==" << " "<< ways[u] <<" "<< ways[j] << " "<< people[j] << endl;
                }
                if (d[j] < fn){
                    fn = d[j];
                    fi = j;
                }
            }
        }
        u = fi;
        // cout << endl;
        if (u == tar){
            break;
        }
    }
    // int ans = count(tar);
    cout << ways[tar] <<" "<< people[tar] << endl;
    return 0;
}
