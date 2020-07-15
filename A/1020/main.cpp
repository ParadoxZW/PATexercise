#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
// #include <mat_print.hpp>
using namespace std;

const unsigned int maxn = 1<<31;

struct node {
    int data;
    node* lchild;
    node* rchild;
};

node* newNode(int v) {
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = 0;
    return Node;
}

int post[32];
int in[32];
int N;
// int leftNum;
// int k;

node* rebuild(int postL, int postR, int inL, int inR) {
    // cout << post[postR] << ' ' << postL << ' ' << postR << ' ' << inL << ' '
        //  << inR << endl;
    if (inL > inR) {
        return NULL;
    }
    node* root = newNode(post[postR]);

    int k, leftNum;

    for (k = inL; k <= inR; k++) {
        if (in[k] == post[postR]) {
            break;
        }
    }
    leftNum = k - inL;

    root->lchild = rebuild(postL, postL + leftNum - 1, inL, k - 1);
    root->rchild = rebuild(postL + leftNum, postR - 1, k + 1, inR);

    return root;
}

node* Root;

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    if (Root == root) {
        printf("%d", root->data);
    } else {
        printf(" %d", root->data);
    }
    preorder(root->lchild);
    preorder(root->rchild);
}

void levelorder() {
    queue<node*> q;
    q.push(Root);
    printf("%d", Root->data);

    while(!q.empty()) {
        node* nd = q.front();
        q.pop();
        if (nd->lchild != NULL){
            q.push(nd->lchild);
            printf(" %d", nd->lchild->data);
        }
        if (nd->rchild != NULL) {
            q.push(nd->rchild);
            printf(" %d", nd->rchild->data);
        }
    }
}

int main(void) {
#ifdef LOCAL
    freopen("./1020/1.txt", "r", stdin);
#endif    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> post[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> in[i];
    }

    Root = rebuild(0, N - 1, 0, N - 1);
    // preorder(Root);
    levelorder();

    return 0;
}