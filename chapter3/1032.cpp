#include <stdio.h>
const int maxn = 100010;
int a[maxn] = {0};

int main(void)
{
    int N, i, x, k=1, best=0;
    scanf("%d", &N);
    while(N--){
        scanf("%d%d", &i, &x);
        a[i] += x;
        k = (i > k)? i : k;
    }
    for (;k >= 1; k--) {
        if (best < a[k]){
            best = a[k];
            i = k;
        }
    }
    printf("%d %d\n", i, best);
    return 0;
}
