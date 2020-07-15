node *findMax(node **proot, node **&qroot) {
    node* iroot = *proot;
    qroot = proot;
    while(iroot->rchild) {
        qroot = &(iroot->rchild);
        iroot = iroot->rchild;
    }
    return iroot;
}

void deleteNode(node* &root, int x) {
    if(root == NULL) return;
    if(root->data == x) {
        if (!root->lchild && !root->rchild) {
            root = NULL;
        } else if (root->lchild) {
            node **pre_;
            node *pre = findMax(&(root->lchild), pre_);
            root->data = pre->data;
            deleteNode(*pre_, pre->data);
        } else {
            node **nxt_;
            node *nxt = findMin(&(root->rchild), nxt_);
            root->data = nxt->data;
            deleteNode(*nxt_, nxt->data);
        }
    } else if(root->lchild > x) {
        deleteNode(root->lchild, x);
    } else {
        deleteNode(root->rchild, x);
    }
}