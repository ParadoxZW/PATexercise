struct node {
    int data;
    node* lchild;
    node* rchild;
}

node* newNode(int v) {
    node* Node = new node;
    Node->data = v;
    Node->lchild = Node->rchild = NULL;
    return Node;
}

void insert(node *&root, int x) {
    if (root == NULL) {
        root = newNode(x);
        return;
    }
    if (/* 满足左子树性质 */) {
        insert(root->lchild, x);
    } else {
        insert(root->rchild, x);
    }
}

void preorder(node* root) {
    if (root == NULL) {
        return;
    }
    visit(root);
    preorder(root->lchild);
    preorder(root->rchild);
}

