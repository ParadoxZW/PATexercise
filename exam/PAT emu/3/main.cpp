#include <bits/stdc++.h>

using namespace std;

const int maxn=100010;
struct Node{
    int height;
    int father;
    vector<int> children;
};

int N;
double p, r;
Node tree[maxn];
int f, root;
int hmax, num;

void DFS(int i, int h){
    if (h> hmax){
        hmax = h;
        num = 1;
    } else if(h==hmax){
        num++;
    }
    for(int j:tree[i].children) {
        DFS(j, h+1);
    }
}


int main() {
    cin >> N >> p >> r;
    for (int i = 0; i < N; i++) {
        scanf("%d", &f);
        if (f != -1) {
        tree[i].father = f;
        tree[f].children.push_back(i);
        } else {
            root = i;
        }
    }
    DFS(root, 1);
    // cout << hmax << endl;
    p *= pow(1 + r*0.01, hmax-1);
    printf("%.2f %d", p, num);
    return 0;
}