#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010;
int inOrder[maxn], preOrder[maxn];

struct Node {
    int v;
    Node *lchild, *rchild;
};

Node *newNode(int v) {
    Node *root = new Node;
    root->v = v;
    root->lchild = NULL;
    root->rchild = NULL;
    return root;
}

Node *build(int inL, int inR, int preL, int preR) {
    if (inL > inR) {
        return NULL;
    }
    int v = preOrder[preL];
    // std::cout << preL << " " << v << std::endl;
    Node *root = newNode(v);
    int k;
    for (k = inL; k <= inR; k++) {
        if (inOrder[k] == v)
            break;
    }
    int tmp = k - inL;
    root->lchild = build(inL, k - 1, preL + 1, preL + tmp);
    root->rchild = build(k + 1, inR, preL + 1 + tmp, preR);
    return root;
}

int N, M;
int x, y, flag, ans;

/**
 * flag:
 * 0: 一个都还没找到
 * 1: 都找到了
 * 2: 找到x
 * 3: 找到y
 */
int dfs(Node *root) {
    // std::cout << root->v << std::endl;
    if (root == NULL) {
        return 0;
    }
    int flag = 0, flag1, flag2;
    if (root->v == x) {
        flag = 2;
        if (x == y) {
            ans = x;
            return 1;
        }
    }
    if (root->v == y) {
        flag = 3;
    }
    flag1 = dfs(root->lchild);
    if (flag1 == 1) {
        return 1;
    }
    if (flag == 2 && flag1 == 3) {
        ans = root->v;
        return 1;
    }
    if (flag == 3 && flag1 == 2) {
        ans = root->v;
        return 1;
    }
    flag2 = dfs(root->rchild);
    if (flag2 == 1) {
        return 1;
    }
    if (flag == 2 && flag2 == 3) {
        ans = root->v;
        return 1;
    }
    if (flag == 3 && flag2 == 2) {
        ans = root->v;
        return 1;
    }
    if ((flag1 == 3 && flag2 == 2) || (flag1 == 2 && flag2 == 3)) {
        ans = root->v;
        return 1;
    }
    if (flag1 != 0) {
        return flag1;
    }
    if (flag2 != 0) {
        return flag2;
    }
    return flag;
}

map<int, int> pos;

int main(void) {
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d", inOrder + i);
        pos[inOrder[i]] = i+1;
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", preOrder + i);
    }
    Node *root = build(0, N - 1, 0, N - 1);
    // std::cout << "ok" << std::endl;
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &x, &y);
        if (pos[x] == 0 && pos[y] == 0) {
            printf("ERROR: %d and %d are not found.\n", x, y);
            continue;
        } else if (pos[x] == 0 || pos[y] == 0) {
            printf("ERROR: %d is not found.\n", pos[x] == 0 ? x : y);
            continue;
        }
        flag = dfs(root);
        if (ans == x) {
            printf("%d is an ancestor of %d.\n", x, y);
        } else if (ans == y) {
            printf("%d is an ancestor of %d.\n", y, x);
        } else {
            printf("LCA of %d and %d is %d.\n", x, y, ans);
        }
    }
    return 0;
}