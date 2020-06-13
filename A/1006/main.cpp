#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int M;
int hh1, mm1, ss1;
int hh2, mm2, ss2;
int fh=23, fm=59, fs=59; // first
int lh=0, lm=0, ls=0; // last
char lock[100], unlock[100], tmp[100];

int main(void) {
    cin >> M;
    for (int i = 0; i < M; i++) {
        scanf("%s %d:%d:%d %d:%d:%d", tmp, &hh1, &mm1, &ss1, &hh2, &mm2, &ss2);
        if (hh1 < fh || (hh1 == fh && mm1 < fm) || 
            (hh1 == fh && mm1 == fm && ss1 <= fs)) {
            fh = hh1;
            fm = mm1;
            fs = ss1;
            sprintf(unlock, "%s", tmp);
        }
        if (hh2 > lh || (hh2 == lh && mm2 < lm) ||
            (hh2 == lh && mm2 == lm && ss2 <= ls)) {
            lh = hh2;
            lm = mm2;
            ls = ss2;
            sprintf(lock, "%s", tmp);
        }
    }
    printf("%s %s", unlock, lock);

    return 0;
}