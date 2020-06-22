#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <string>
#include <vector>
// #include <mat_print.hpp>
using namespace std;

const int maxn = 31000;

struct info {
    char regs[15];
    int nlo;
    int score;
};

info tee[maxn];
int idx[maxn];
int lr[110];
int ls[110];
int ln[110];
int N, K;
int x1, x2=-1, x3, k;

bool cmp(int a, int b) {
    if (tee[a].score != tee[b].score) {
        return tee[a].score > tee[b].score;
    } else {
        return strcmp(tee[a].regs, tee[b].regs) < 0;
    }
}

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        for (int j = 0; j < K; j++) {
            cin >> tee[k].regs >> tee[k].score;
            tee[k].nlo = i + 1;
            idx[k] = k;
            k++;
        }
    }
    sort(idx, idx + k, cmp);
    cout << k << endl;
    memset(ls, -1, sizeof(ls));
    for (int i = 0; i < k; i++) {
        info &t = tee[idx[i]];
        if (t.score != x2) {
            x1 = i + 1;
            x2 = t.score;
        }
        if (t.score != ls[t.nlo]) {
            x3 = ++lr[t.nlo];
            ln[t.nlo] = x3;
            ls[t.nlo] = t.score;
        } else {
            x3 = ln[t.nlo];
            ++lr[t.nlo];
        }
        printf("%s %d %d %d\n", t.regs, x1, t.nlo, x3);
    }
    return 0;
}