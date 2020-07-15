#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
// #include <mat_print.hpp>
using namespace std;

const int maxn = 10010;
const int opentime = 8 * 3600;
const int clostime = 17 * 3600;
int next_time[110];

struct Cust {
    int t;
    int p;
};

struct Wndw {
    int i, nt;
    friend bool operator< (Wndw a, Wndw b) {
        return a.nt > b.nt;
    }
};

Cust cust[maxn];

bool cmp(Cust a, Cust b) {
    return a.t < b.t;
};

priority_queue<Wndw> pq;

int calc_time(int hh, int mm, int ss){
    return hh * 3600 + mm * 60 + ss;
}

int N, K;
int hh, mm, ss, pp;
int s;

int main(void) {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        scanf("%d:%d:%d %d", &hh, &mm, &ss, &pp);
        cust[i].t = calc_time(hh, mm, ss);
        cust[i].p = pp * 60;
    }
    sort(cust, cust + N, cmp);

    for (int i = 0; i < K; i++) {
        Wndw w = {.i = i, .nt = opentime};
        pq.push(w);
    }

    // fill(next_time, next_time + K, opentime);
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        Cust& ct = cust[i];
        if(ct.t > clostime ) {
            break;
        }
        Wndw w = pq.top();
        pq.pop();
        // cout << w.i << ' ' << w.nt << endl;
        s += max(w.nt - ct.t, 0);
        Wndw nw = {.i = w.i, .nt = max(w.nt, ct.t) + ct.p};
        // if (nw.nt < clostime)
        pq.push(nw);
        cnt++;
    }
    // cout << s << endl;
    // cout << cnt << endl;
    printf("%.1f", s * 1. / cnt / 60);
    return 0;
}