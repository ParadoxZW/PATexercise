#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <vector>
// #include<mat_print.hpp>
using namespace std;
#define likely(x) __builtin_expect(!!(x), 1) // gcc内置函数, 帮助编译器分支优化
#define unlikely(x) __builtin_expect(!!(x), 0)

    const int maxn = 1111;
vector<int> G[maxn];
vector<int> bs[maxn];
int belong[maxn];
int edges[maxn], hm[maxn], dfn[maxn], low[maxn];
bool vis[maxn], ring[maxn], path_[maxn], flag[maxn];
vector<int> path, tmp;

int N, M, K, block = 0, curr, new_num, ll, lg, le, rest;
int cP, tst, root;

void dfs_all(int v, int b, int f) {
    int child = 0;
    bs[b].push_back(v);
    belong[v] = b;
    vis[v] = true;
    // path.push_back(v);
    // cout << g << '{';
    // path_[v] = true;
    dfn[v] = low[v] = ++tst;
    // for (auto i = path.begin(); i!=path.end();i++){
        // cout << *i << ',';
    // }
    // cout << endl;
    // cout << (path|vw::all) << endl;
    // int g = *(path.end() - 2);
    for (auto i : G[v]) {
        edges[b]++;
        // if(path_[i] && i != g){
        //     // if (i == 1){
        //     //     hm[block] = max((int)path.size(), (int)hm[block]);
        //     // }
        //     // cout << ".."<<i << endl;
        //     ring[i] = true;
        //     // cout << *j << ' ' << i << endl;
        //     for(auto j = path.end() - 1; *j != i; j--){
        //         // cout << *j << ' '<< i << endl;
        //         ring[*j] = true;
        //     }
        //     // cout << (ring | vw::take(N+1)) << endl;
        // }
        if (likely(!vis[i])) {
            child++;
            dfs_all(i, b, v);
            low[v] = min(low[v], low[i]);
            if (unlikely(v == root && child >= 2)) {
                flag[v] = true;
            } else if (v != root && low[i] >= dfn[v]) {
                flag[v] = true;
            }
        }else if (unlikely(i != f)) {
            low[v] = min(low[v], dfn[i]);
        }
    }
    // path.pop_back();
    // path_[v] = false;
}

void dfs(int v) {
    if (v == cP)
        return;
    vis[v] = true;
    for (auto i : G[v]) {
        if (!vis[i]) {
            dfs(i);
        }
    }
}

int main() {
    // cin >> N >> M >> K;
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for (int i = 1; i <= N; i++) {
        // split graph
        if (!vis[i]) {
            tst = 0;
            root = i;
            edges[block]++;
            dfs_all(i, block, i);
            block++;
        }
    }

    // cout << '[' << hm[0] << endl;
    // cout << (flag|vw::take(N+1)) << endl;
    int minn = (N - 2) * (N - 3) / 2 + 1;
    for (int q = 0; q < K; q++) {
        scanf("%d", &cP);
        ll = G[cP].size();
        // cout << M - ll << " " << (N - 2) * (N - 3) / 2 + 1 << endl;

        if (unlikely(N > 4 && M - ll >= minn)) {
                cout << 0 << endl;
                continue;
        }
        
        curr = belong[cP];
        lg = bs[curr].size();
        if(unlikely(lg == 1)) {
            printf("%d\n", block - 2);
            // cout << block - 2 << endl;
            continue;
        }
        // if (hm[curr] == lg) {
        //     cout << block - 1 << endl;
        //     continue;
        // }
        if(unlikely(ll == 1 || !flag[cP])){
            printf("%d\n", block - 1);
            // cout << block - 1 << endl;
            continue;
        }
        le = edges[curr] / 2;
        rest = le - ll;
        // cout << '[' << block << endl;
        // cout << "bedge" << le << "|ll" << ll << "|nodes" << lg << endl;
        if(unlikely(rest <= 1)) {
            printf("%d\n", block + lg - (rest + 3));
            // cout << block + lg - (rest + 3) << endl;
            continue;
        }
        if (unlikely(rest >= (lg - 2) * (lg - 3) / 2 + 1)) {
            printf("%d\n", block - 1);
            // cout << block - 1 << endl;
            continue;
        }
        // cout << "ring "<< ring[cP] << endl;
        // cout << "xx" << endl;

        // if(!ring[cP]){
        //     cout << block + ll - 2 << endl;
        //     continue;
        // }else{
        //     if (ll == 2){
        //         cout << block - 1 << endl;
        //         continue;
        //     }
        // }
        // cout << "ok" << endl;

        // tmp.clear();
        new_num = 0;
        // for (auto i: G[cP]) {
        //     if (flag[i]){
        //         new_num++;
        //     } else {
        //         tmp.push_back(i);
        //     }
        // }
        // if (tmp.size() == 2) {
        //     new_num++;
        //     cout << block + new_num - 2 << endl;
        //     continue;
        // }
        memset(vis, false, N + 2);
        // int i;
        // while (tmp.size() > 0) {
        //     i = tmp.back();
        //     if (vis[i]){
        //         tmp.pop_back();
        //         continue;
        //     }
        //     if (tmp.size() <= 2) {
        //         new_num++;
        //         // cout << "ss " << new_num << endl;
        //         break;
        //     }
        //     tmp.pop_back();
        //     dfs(i);
        //     new_num++;
        // // cout << "ss " <<new_num << '|' << tmp.size() << endl;
        // }
        // cout << block + new_num - 2 << endl;

        // cout << "ok" << endl;
        for(auto i: G[cP]){
            // if (flag[i]) {
            //     new_num++;
            //     continue;
            // }
            if (!vis[i]) {
                // cout << ']' << i << endl;
                dfs(i);
                new_num++;
            }
        }
        printf("%d\n", block + new_num - 2);
        // cout << block + new_num - 2 << endl;
        // cout << "\n\n" << endl;
    }
}
