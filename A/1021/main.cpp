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

const int maxn = 10010;

vector<int> G[maxn];
int father[maxn];
bool isRoot[maxn];

int findFather(int v) {
    if (father[v] == v) return v;
    else {
        int f = findFather(father[v]);
        father[v] = f;
        return f;
    }
}

void Union(int a, int b) {
    int faA = findFather(a);
    int faB = findFather(b);
    if (faA != faB) {
        father[faB] = faA;
    }
}

void init(int N) {
    for (int i = 1; i <= N; i++) {
        father[i] = i;
    }
}

int calBlock(int N) {
    int block = 0;
    for (int i = 1; i <= N; i++) {
        isRoot[findFather(i)] = true;  // 不能直接用father[i]
    }
    for (int i = 1; i <= N; i++) {
        block += isRoot[i];
    }
    return block;
}

int x, y, N;
int maxH;
set<int> tmp, ans;

void DFS(int u, int height, int pre) {
    if (height > maxH) {
        tmp.clear();
        tmp.insert(u);
        maxH = height;
    } else if (height == maxH) {
        tmp.insert(u);
    }
    for (int i = 0; i < G[u].size(); i++) {
        if (G[u][i] == pre) continue;
        DFS(G[u][i], height + 1, u);
    }
}

int main(void) {
    cin >> N;
    init(N);
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
        Union(x, y);
    }
    int block = calBlock(N);
    if (block > 1) {
        printf("Error: %d components", block);
    } else {
        DFS(1, 1, -1);
        ans = tmp;
        set<int>::iterator it = ans.begin();
        DFS(*it, 1, -1);
        for (auto i: tmp) {
            ans.insert(i);
        }
        for (auto i: ans){
            printf("%d\n", i);
        }
    }

    return 0;
}