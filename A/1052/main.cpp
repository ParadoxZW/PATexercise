#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
// #include <mat_print.hpp>
using namespace std;

const int maxn = 100010;

struct node {
    int addr, key, nxt;
    bool valid;
};

int N, head;
node list[maxn];
int ord[maxn];
vector<node> linked;
bool cmp(int a, int b) {
    return linked[a].key < linked[b].key;
}
int x1, x2, x3;

int main(void) {
    cin >> N >> head;
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &x1, &x2, &x3);
        node &nd = list[x1];
        nd.addr = x1;
        nd.key = x2;
        nd.nxt = x3;
        nd.valid = true;
    }
    int p = head, k = 0;
    while(p != -1 && list[p].valid) {
        linked.push_back(list[p]);
        p = list[p].nxt;
        ord[k] = k;
        k++;
    }
    sort(ord, ord+k, cmp);
    if (k == 0) {
        printf("0 -1\n");
    } else {
        printf("%d %05d\n", k, linked[ord[0]].addr);
        for (int i = 0; i < k; i++) {
            node &nd = linked[ord[i]];
            if (i != k - 1)
                printf("%05d %d %05d\n", nd.addr, nd.key, linked[ord[i+1]].addr);
            else
                printf("%05d %d -1\n", nd.addr, nd.key);
        }
    }
    return 0;
}