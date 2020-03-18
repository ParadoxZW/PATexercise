#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main(void)
{
    int a[5] = {1, 2, 3, 4, 5};
    memset(a, -2, sizeof(a));
    for (int i = 0; i < 5; ++i) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
