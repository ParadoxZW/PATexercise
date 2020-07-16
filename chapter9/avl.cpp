struct node {
    int v, height;
    node *lchild, *rchild;
};

node* newNode(int v) {
    node *Node = new node;
    Node->v = v;
    Node->height = 1;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

int getHehight(node* root) {
    if (!root) return 0;
    return root->height;
}

int getBalanceFactor(node* root) {
    return getHehight(root->lchild) - getHehight(root-rchild);
}

void updateHeight(node* root) {
    root->height = max(
        getHehight(root->lchild),
        getHehight(root->rchild)
    );
}

void L(node* &root) {
    node* tmp = root->rchild;
    root->rchild = tmp->lchild;
    tmp->lchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void R(node* &root) {
    node* tmp = root->lchild;
    root->lchild = tmp->rchild;
    tmp->rchild = root;
    updateHeight(root);
    updateHeight(tmp);
    root = tmp;
}

void insert(node* &root, int v) {
    if (root == NULL) {
        root = newNode(v);
        return;
    }
    if (v < root->v) {
        insert(root->lchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == 2) {
            if (getBalanceFactor(root->lchild) == 1) {  // LL
                R(root);
            } else {  // LR
                L(root->lchild);
                R(root);
            }
        }
    } else {
        insert(root->rchild, v);
        updateHeight(root);
        if (getBalanceFactor(root) == -2) {
            if (getBalanceFactor(root->rchild) == -1) { // RR
                L(root);
            } else { // RL
                R(root->rchild);
                L(root);
            }
        }
    }
}