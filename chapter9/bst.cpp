node *findMax(node *root) {
    while(root->rchild) {
        root = root->rchild;
    }
    return root;
}

void deleteNode(node* &root, int x) {
    if(root == NULL) return;
    if(root->data == x) {
        if (!root->lchild && !root->rchild) {
            root = NULL;
        } else if (root->lchild) {
            node *pre = findMax(root->lchild);
            root->data = pre->data;
            deleteNode(root->lchild, pre->data);
        } else {
            node *nxt = findMin(root->rchild);
            root->data = nxt->data;
            deleteNode(root->rchild, nxt->data);
        }
    } else if(root->lchild > x) {
        deleteNode(root->lchild, x);
    } else {
        deleteNode(root->rchild, x);
    }
}