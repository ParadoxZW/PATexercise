/**
 * 统计数列元素左边比该元素小的元素的个数
*/

#include <cstdio>
#include <cstring>

const int maxn = 100010;
int c[maxn];
#define lowbit(x) ((x) & (-x))

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
        scanf("%d", &x);
        update(x, 1);
        printf("%d\n", getSum(x-1));
    }

    return 0;
}