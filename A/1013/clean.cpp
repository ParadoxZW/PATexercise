/**
 * steps：
 * 1. 分割连通分量（dfs），并找到每个分量中的割点（tarjan）
 * 2. 仅处理 查询点所在分量（bs[belong[cP]]） 是否会被查询点割裂
 * 3. 进行一些小的剪枝，例如bs[belong[cP]].size() == 1
 * 4. 如果cP不是割点，连通性保持不变，需要加的边数即初始的block-1
 * 5. 从cP相连的点出发，dfs，计算连通分量个数
 */
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
int edges[maxn], dfn[maxn], low[maxn];
bool vis[maxn], flag[maxn];
vector<int> tmp;

int N, M, K, block = 0, curr, new_num, ll, lg, le, rest;
int cP, tst, root;

void dfs_all(int v, int b, int f) {
    int child = 0;
    bs[b].push_back(v);
    belong[v] = b;
    vis[v] = true;
    dfn[v] = low[v] = ++tst;
    for (auto i : G[v]) {
        edges[b]++;
        if (likely(!vis[i])) {
            child++;
            dfs_all(i, b, v);
            low[v] = min(low[v], low[i]);
            if (unlikely(v == root && child >= 2)) {
                flag[v] = true;
            } else if (v != root && low[i] >= dfn[v]) {
                flag[v] = true;
            }
        } else if (unlikely(i != f)) {
            low[v] = min(low[v], dfn[i]);
        }
    }
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

    int minn = (N - 2) * (N - 3) / 2 + 1;
    for (int q = 0; q < K; q++) {
        scanf("%d", &cP);
        ll = G[cP].size();

        if (unlikely(N > 4 && M - ll >= minn)) {
            printf("0\n");
            continue;
        }

        curr = belong[cP];
        lg = bs[curr].size();
        if (unlikely(lg == 1)) {
            printf("%d\n", block - 2);
            continue;
        }
        if (unlikely(ll == 1 || !flag[cP])) {
            printf("%d\n", block - 1);
            continue;
        }

        le = edges[curr] / 2;
        rest = le - ll;
        if (unlikely(rest <= 1)) {
            printf("%d\n", block + lg - (rest + 3));
            continue;
        }
        if (unlikely(rest >= (lg - 2) * (lg - 3) / 2 + 1)) {
            printf("%d\n", block - 1);
            continue;
        }
        
        new_num = 0;
        memset(vis, false, N + 2);
        for (auto i : G[cP]) {
            if (!vis[i]) {
                dfs(i);
                new_num++;
            }
        }
        printf("%d\n", block + new_num - 2);
    }
}
