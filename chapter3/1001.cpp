#include <stdio.h>

int main(void)
{
    int cnt = 0, x;
    scanf("%d", &x);
    while(x!=1){
        x = (x%2)? (3*x+1)/2 : x/2;
        cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
