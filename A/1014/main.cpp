#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>
// #include <mat_print.hpp>
using namespace std;

const int maxn = 9 * 60;

struct custom {
    // int id;
    int line;
    int dt; // done_time
    friend bool operator<(custom a, custom b) {
        if (a.dt != b.dt)  
            return a.dt > b.dt;
        else
            return a.line > b.line; // important
    }
};
queue<int> win[21]; // windows, line-front queue
int nt[1010];       // need_time
int ddt[1010];      // done_time
int N, M, K, Q;
int t1, t2, t3;
// int li;
int q, hh, mm;

priority_queue<custom> pq;

int main(void) {
    cin >> N >> M >> K >> Q;
    for (int i = 0; i < K; i++) {
        cin >> nt[i];
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (t1 >= K) {
                break;
            }
            if (win[j].empty())
                t2 = 0;
            else
                t2 = ddt[win[j].back()];
            win[j].push(t1);
            // if (t2 >= 0 && t2 < maxn)
            ddt[t1] = t2 + nt[t1];
            // else
            // ddt[t1] = -1;
            t1++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (!win[i].empty()) {
            t2 = win[i].front();
            custom ct = {.line = i, .dt = ddt[t2]};
            pq.push(ct);
        }
    }
    while (!pq.empty()) {
        custom ct = pq.top();
        pq.pop();
        t2 = ddt[win[ct.line].back()];
        win[ct.line].pop();
        if (t1 < K) {
            win[ct.line].push(t1);
            // if (t2 >= 0 && t2 < maxn)
            ddt[t1] = t2 + nt[t1];
            // else
            // ddt[t1] = -1;
            t1++;
        } else {
            break;
        }
        if (!win[ct.line].empty()) {
            t3 = win[ct.line].front();
            custom ct2 = {.line = ct.line, .dt = ddt[t3]};
            pq.push(ct2);
        }
    }
    for (int i = 0; i < Q; i++) {
        cin >> q;
        t2 = ddt[q - 1];
        t3 = nt[q - 1];
        if (t2 - t3 >= maxn) { // important
            printf("Sorry\n");
        } else {
            hh = t2 / 60;
            mm = t2 % 60;
            printf("%02d:%02d\n", 8 + hh, mm);
        }
    }

    return 0;
}