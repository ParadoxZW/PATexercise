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

int p;
Node* randBT() {
    Node* root = newNode(0);
    // p++;
    if (rand() % 10 < 3) {
        root->lchild = randBT();
    }
    root->v = p;
    p++;
    if (rand() % 10 < 3) {
        root->rchild = randBT();
    }
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

int qx, qy;

int lca(int inl, int inr, int preroot, int a, int b) { // l和r为中序中的位置
    if (inl > inr)
        return -1;
    // int inroot = pos[preOrder[preroot]] - 1; // inroot为中序中根节点的位置
    int inroot = preOrder[preroot]; // inroot为中序中根节点的位置
    int ain = a, bin = b;
    if (ain < inroot && bin < inroot) { //若a和b都在左子树中
        return lca(inl, inroot - 1, preroot + 1, a, b);
    } else if ((ain < inroot && bin > inroot) ||
               (ain > inroot &&
                bin < inroot)) { //若a和b一个在左子树，一个在右子树
        return inOrder[inroot];
    } else if (ain > inroot && bin > inroot) { //若a和b都在右子树中
        return lca(inroot + 1, inr, preroot + 1 + (inroot - inl), a, b);
    } else if (ain == inroot) {
        return a;
    } else if (bin == inroot) {
        return b;
    }
    return -1;
}
int ans2;

int inTravel(Node* root, int idx) {
    if (root == NULL)
        return idx;
    idx = inTravel(root->lchild, idx);
    inOrder[idx++] = root->v;
    idx = inTravel(root->rchild, idx);
    return idx;
}

int preTravel(Node *root, int idx) {
    if (root == NULL)
        return idx;
    preOrder[idx++] = root->v;
    idx = preTravel(root->lchild, idx);
    idx = preTravel(root->rchild, idx);
    return idx;
}

void display() {
    for (int i = 0; i < N; i++) {
        printf("%d ", inOrder[i]);
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", preOrder[i]);
    }
}

int main(void) {
    srand((unsigned)time(NULL));
    for (int w = 0; w < 100; w++) {
        p = 0;
        Node *root = randBT();
        N = p;
        for (int v = 0; v < 100; v++) {
            x = rand() % p;
            y = rand() % p;    
            dfs(root);
            // std::cout << "ok" << std::endl;
            inTravel(root, 0);
            preTravel(root, 0);
            // std::cout << "ok" << N << std::endl;
            ans2 = lca(0, N - 1, 0, x, y);
            if (ans != ans2) {
                printf("ans: %d %d %d %d %d\n", p, x, y, ans, ans2);
                display();
                printf("\n\n");
            }
        }
    }
    // std::cout << "ok" << std::endl;
    // for (int i = 0; i < M; i++) {
    //     scanf("%d %d", &x, &y);
    //     if (pos[x] == 0 && pos[y] == 0) {
    //         printf("ERROR: %d and %d are not found.\n", x, y);
    //         continue;
    //     } else if (pos[x] == 0 || pos[y] == 0) {
    //         printf("ERROR: %d is not found.\n", pos[x] == 0 ? x : y);
    //         continue;
    //     }
    //     flag = dfs(root);
    //     if (ans == x) {
    //         printf("%d is an ancestor of %d.\n", x, y);
    //     } else if (ans == y) {
    //         printf("%d is an ancestor of %d.\n", y, x);
    //     } else {
    //         printf("LCA of %d and %d is %d.\n", x, y, ans);
    //     }
    // }
    return 0;
}