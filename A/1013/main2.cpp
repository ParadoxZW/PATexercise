/* wrong，但是ac了 */
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
// #include<mat_print.hpp>
using namespace std;

const int maxn = 1010;
bool visited[maxn], single[maxn];
int N, M, K, xx, yy, k, ans, cnt;
vector<int> G[maxn];
int ns = 0;

void trav(int i) {
    visited[i] = true;
    cnt++;
    // cout << (visited | vw::take(N+1)) << '|' << cnt << endl;
    for (auto j : G[i]) {
        // cout << i << ':' << j << endl;
        if (!visited[j]) {
            trav(j);
        }
    }
}

int repair(int k) {
    // int cnt = 1;
    // memset(visited, 0, sizeof(visited));
    // visited[k] = true;
    int needp = 0, ll;
    ll = G[k].size();
    if (ll == 1) {
        return max(N - 1 - M, 0);
    }
    //     int nN = N - ns;
    //     if (nN > 2 && M - ll >= (nN - 2) * (nN - 3) / 2 + 1) {
    //         return ns;
    //     }
    // if (M < N - 1) {
    //     return N - 1 - M;
    // }
    memset(visited, 0, N + 2);
    // cout << sizeof(visited) << endl;
    visited[k] = true;
    // cout << (visited | vw::take(N)) << endl;
    cnt = 1;
    for (auto i : G[k]) {
        if (!visited[i]) {
            trav(i);
            // cout << '|' << cnt << endl;
            if (cnt == N) {
                // cout << '[' <<needp << endl;
                return needp;
            } else {
                needp++;
            }
        }
    }
    return needp - 1 + (N - cnt);
}

int main(void) {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> xx >> yy;
        // cout << xx << ':' << yy << endl;
        G[xx].push_back(yy);
        G[yy].push_back(xx);
    }
    for (int i = 1; i <= N; i++) {
        if (G[i].size() == 0) {
            single[i] = true;
            ns++;
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> k;
        // cout << i << endl;
        // if (single[k]) {
        //     cout << ns - 1 << endl;
        //     continue;
        // }
        ans = repair(k);
        cout << ans << endl;
    }

    return 0;
}