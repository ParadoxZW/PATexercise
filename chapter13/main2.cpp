/**
 * 统计数列元素左边比该元素小的元素的个数
 * 离散化版本
 */

#include <cstdio>
#include <cstring>
#include <algorithm>

const int maxn = 100010;
int c[maxn];
int A[maxn];
#define lowbit(x) ((x) & (-x))

struct Node {
    int val;
    int pos;
} tmp[maxn];

bool cmp(Node a, Node b) {
    return a.val < b.val;
}


int getSum(int x) {
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        sum += c[i];
    }
    return sum;
}

void update(int x, int v) {
    for (int i = x; i <= N; i += lowbit(i)) {
        c[i] += v;
    }
}

int main(void) {
    int n, x;
    scanf("%d", &n);
    memset(c, 0, sizeof(c));
    for (int i = 0; i < n; i++) {
        scanf("%d", &tmp[i].val);
        tmp[i].pos = i;
    }
    sort(tmp, tmp+n, cmp);
    for (int i = 0; i < n; i++) {
        if (i == 0 || tmp[i].val != tmp[i-1].val) {
            A[tmp[i].pos] = i+1;
        } else {
            A[tmp[i].pos] = A[tmp[i - 1].pos];
        }
    }
    for (int i = 0; i < n; i++) {
        update(A[i], 1);
        printf("%d\n", getSum(x - 1));
    }

    return 0;
}