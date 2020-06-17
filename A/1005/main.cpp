#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn = 110;
const char w[10][10] = {"zero", "one",   "two",   "three", "four", "five",
                        "six",  "seven", "eight", "nine"};
char c[maxn], o[maxn];
int s = 0;

int main(void) {
    scanf("%s", c);
    for (int i = 0; i < strlen(c); i++) {
        s += c[i] - '0';
    }
    sprintf(o, "%d", s);
    printf("%s", w[o[0] - '0']);
    for (int i = 1; i < strlen(o); i++) {
        printf(" %s", w[o[i] - '0']);
    }
    return 0;
}