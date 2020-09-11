#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <stdio.h>
#include <vector>
#define MAX 10020
#define INF 0x3f3f3f3f
typedef long long ll;
using namespace std;

map<int, int> pos;     //记录中序中的节点的位置
int in[MAX], pre[MAX]; //中序和前序
int n, m, a, b;

void lca(int inl, int inr, int preroot, int a, int b) { // l和r为中序中的位置
    if (inl > inr)
        return;
    int inroot = pos[pre[preroot]]; // inroot为中序中根节点的位置
    int ain = pos[a], bin = pos[b];
    if (ain < inroot && bin < inroot) { //若a和b都在左子树中
        lca(inl, inroot - 1, preroot + 1, a, b);
    } else if ((ain < inroot && bin > inroot) ||
               (ain > inroot &&
                bin < inroot)) { //若a和b一个在左子树，一个在右子树
        printf("LCA of %d and %d is %d.\n", a, b, in[inroot]);
    } else if (ain > inroot && bin > inroot) { //若a和b都在右子树中
        lca(inroot + 1, inr, preroot + 1 + (inroot - inl), a, b);
    } else if (ain == inroot) {
        printf("%d is an ancestor of %d.\n", a, b);
    } else if (bin == inroot) {
        printf("%d is an ancestor of %d.\n", b, a);
    }
}

int main() {
    scanf("%d%d", &m, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &in[i]);
        pos[in[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", &pre[i]);
    }
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
        if (pos[a] == 0 && pos[b] == 0) {
            printf("ERROR: %d and %d are not found.\n", a, b);
        } else if (pos[a] == 0 || pos[b] == 0) {
            printf("ERROR: %d is not found.\n", pos[a] == 0 ? a : b);
        } else {
            lca(1, n, 1, a, b);
        }
    }
    return 0;
}
