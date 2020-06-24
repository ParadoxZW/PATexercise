#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
// #include <mat_print.hpp>
using namespace std;

const unsigned int maxn = 1<<31;

struct node {
    int f, l, r, k;
};

void build(int root, int left, int rght, int rt_idx) {
    int new_root;
    if () {
        
    }
    for (int i = left; i < rght; i++) {
        if (inor[i] == post[root]) {
            new_root = i;
            break;
        }
    }
    int lson, rson;

    node lnd = {.f = rt_idx, .k = post[losn]};
    node rnd = {.f = rt_idx, .k = post[rosn]};
    tree.push_back(lnd);
    tree.push_back(rnd);
    tree[rt_idx].l = tree.size() - 2;
    tree[rt_idx].r = tree.size() - 1;

    build(lson, left, new_root);
    build(rson, new_root + 1, rght)
}

// node tree[maxn];
vector<node> tree;
int post[32];
int inor[32];
int N;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> inor[i];
    }
    

    return 0;
}