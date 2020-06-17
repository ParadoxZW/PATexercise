#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

const int maxn = 10010;
int v[maxn], rc[maxn][110];
bool dp[maxn][110];
int N, M, j;
vector<int> vec;

int main(void) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        dp[i][0] = true;
    }
    sort(v + 1, v + N + 1, greater<int>());
    // cout << v << endl;
    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        // cout << v[i] << endl;
        for (int m = 1; m <= M; m++) {
            if (m - v[i] >= 0) {
                if (dp[i - 1][m - v[i]]) {
                    dp[i][m] = true;
                    rc[i][m] = i;
                } else if (dp[i - 1][m]) {
                    dp[i][m] = true;
                    rc[i][m] = rc[i - 1][m];
                } else {
                    dp[i][m] = false;
                }
            } else {
                if (dp[i - 1][m]) {
                    dp[i][m] = true;
                    rc[i][m] = rc[i - 1][m];
                } else {
                    dp[i][m] = false;
                }
            }
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         cout << rc[i][j] << " ";
    //     }
    //     cout << endl;
    // }
// #define print_mat(H, W) [=](int mat[H][]) {for_each(mat, mat + H, [=](int *a){for_each(a, a + W, [=](int e) { cout << e << " "; });cout << endl;});}
//     print_mat(N, M)(rc);
#define print_mat(mat,H,W) for_each(mat, mat + H, [=](int *a){for_each(a, a + W, [=](int e) { cout << e << " "; });cout << endl;})
    print_mat(rc, N+1, M+1);

    if (dp[N][M]) {
        char s[maxn];
        int i = rc[N][M];
        cout << v[i];
        M -= v[i];
        while (M) {
            i = rc[i - 1][M];
            cout << " " << v[i];
            M -= v[i];
        }
        cout << s << endl;
    } else {
        cout << "No Solution" << endl;
    }
    return 0;
}