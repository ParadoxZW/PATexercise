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

const int maxn = 30;
int N, a[maxn];

struct Node {
    int v, height;
    Node *lchild, *rchild;
};

Node *newNode(int v) {
    Node *root = new Node;
    root->v = v;
    root->height = 1;
    root->lchild = root->rchild = NULL;
    return root;
}

int getH(Node* root) {
    if (!root)
        return 0;
    return root->height;
}

void updateH(Node* root) {
    root->height = max(getH(root->lchild), getH(root->rchild)) + 1;
}

int getBF(Node *root) { return getH(root->lchild) - getH(root->rchild); }

void L(Node* &root) {
    Node *tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateH(root);
    root = tmp;
}

void R(Node *&root) {
    Node *tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateH(root);
    root = tmp;
}

void insert(Node* &root, int v) {
    if (root==NULL) {
        root = newNode(v);
        return;
    } 
    if (v < root->v) {
        insert(root->lchild, v);
        if (getBF(root) == 2) {
            if (getBF(root->lchild) == 1) {
                L(root);
            } else {
                R(root->lchild);
                L(root);
            }
        }
        updateH(root);
    } else {
        insert(root->rchild, v);
        if (getBF(root) == -2) {
            if (getBF(root->rchild) == -1) {
                R(root);
            } else {
                L(root->rchild);
                R(root);
            }
        }
        updateH(root);
    }
}

Node* create(int s[]) {
    Node* root = NULL;
    for (int i = 0; i < N; i++) {
        insert(root, s[i]);
    }
    return root;
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    Node *root = create(a);
    cout << root->v << endl;
    return 0;
}