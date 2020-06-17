/**
 * 剔除不喜欢的颜色，转化为LIS
 */

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 10010;

int N, M, L, idx, tmp, j = 1, ans = -1;
int fav[210], dp[maxn], rem[maxn];

int main(void) {
    cin >> N;
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> idx;
        fav[idx] = i + 1;
    }
    cin >> L;
    for (int i = 0; i < L; i++) {
        cin >> tmp;
        if (fav[tmp]) {
            rem[j] = fav[tmp];
            j++;
        }
    }
    for (int i = 1; i < j; i++) {
        dp[i] = 1;
        for (int k = 1; k < i; k++) {
            if (rem[k] <= rem[i] && dp[k] + 1 > dp[i]) {
                dp[i] = dp[k] + 1;
            }
        }
        ans = max(dp[i], ans);
    }
    cout << ans << endl;
    return 0;
}