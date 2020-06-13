#include<iostream>
#include<stdio.h>
using namespace std;

struct Node {
    int nth_layer;
    int num_children;
    // int children[110];
};

int ans[110], N, M, L, idx, k, idy;
Node ns[110];

int main(void) {
    /**
     * 输入节点的顺序在树中必须是从上到下的才work，
     * 否则nth_layer计算错误
    */
    cin >> N;
    if (N == 0)
        return 0;
    cin >> M;
    if (N == 1 && M == 0) {
        printf("1");
        return 0;
    }
    ans[0] = 1;
    for (int i = 0; i < M; ++i) {
        cin >> idx >> k;
        ns[idx].num_children = k;
        ans[ns[idx].nth_layer]--;
        L = ns[idx].nth_layer + 1;
        ans[L] += k;
        for (int j = 0; j < k; ++j) {
            cin >> idy;
            // ns[idx].children[j] = idy;
            ns[idy].nth_layer = L;
        }
    }
    for (int i = 0; i < L + 1; i++) {
        printf("%d", ans[i]);
        if (i != L) {
            printf(" ");
        }
    }

    return 0;
}
