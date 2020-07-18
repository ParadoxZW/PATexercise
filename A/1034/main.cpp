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


const int maxn = 1010;
vector<Node> Adj[maxn];
bool vis[maxn];
int weight[maxn];
map<string, int> name2id;
int N, K;
char n1[5], n2[5];
char id2name[maxn][5];
int w, cnt, idx;
int u, v, tmp;
int gang;
int head[maxn], num[maxn];

void DFS(int s) {
    num[cnt]++;
    if (weight[head[cnt]] < weight[s]) {
        head[cnt] = s;
    }
    for (auto j:Adj[s]) {
        v = j.to;
        w = j.len;
        // cout << w << endl;
        if (!vis[v] && w > K) {
            cout << v << " " << w << endl;
            vis[v] = true;
            DFS(v);
        }
    }
}

int main(void) {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        scanf("%s %s %d", n1, n2, &w);
        string s1 = n1;
        string s2 = n2;
        auto it1 = name2id.find(s1);
        if (it1 == name2id.end()){
            name2id[s1] = idx;
            strcpy(id2name[idx], n1);
            u = idx;
            idx++;
        } else {
            u = it1->second;
        }
        auto it2 = name2id.find(s2);
        if (it2 == name2id.end()) {
            name2id[s2] = idx;
            strcpy(id2name[idx], n2);
            v = idx;
            idx++;
        } else {
            v = it2->second;
        }
        // cout << i << endl;
        Node to_v = {.to = v, .len=w};
        Node to_u = {.to = u, .len=w};
        Adj[u].push_back(to_v);
        Adj[v].push_back(to_u);
        weight[u] += w;
        weight[v] += w;
    }
    cout << idx << endl;
    for (int i = 0; i < idx; i++) {
        if(!vis[i]) {
            // cout << i << endl;
            vis[i] = true;
            // num[cnt]++;
            // head[cnt] = i;
            DFS(i);
            cnt++;
        }
    }
    cout << cnt << endl;
    for (int i = 0; i < cnt; i++) {
        if (num[i] > 2) {
            gang++;
        }
    }

    cout << gang << endl;
    for (int i = 0; i < cnt; i++) {
        if (num[i] > 2) {
            cout << id2name[head[i]] << " " << num[i] << endl;
        }
    }
    return 0;
}