#include <iostream>
#include <stdio.h>
using namespace std;

const int L = 5;

void out(int a[]) {
    for (int k = 0; k < L; ++k) {
        printf("%d ", a[k]);
    }
    printf("\n");
}

int main(void)
{
    int a[L] = {3, 4, 2, 5, 1};
    for (int i = 1; i < L; ++i) {
        for (int j = 0; j < L - i; j++) {
            if (a[j] > a[j+1]) {
                int tmp;
                tmp = a[j];
                a[j] = a[j+1];
                a[j+1] = tmp;
            }
        } 
    }
    out(a);
    return 0;
}
