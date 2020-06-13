#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 1010;
int dp[maxn][maxn];
char s[maxn];
int slen, j, ans = 1;

int main(void) {
    cin.getline(s, maxn);
    slen = strlen(s);
    for (int i = 0; i < slen; i++) {
        dp[i][i] = 1;
        if (i + 1 < slen) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                ans = 2;
            }
        }
    }
    for (int l = 3; l < slen + 1; l++) {
        for (int i = 0; i + l - 1 < slen; i++) {
            j = i + l - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
                dp[i][j] = 1;
                ans = l;
            }
        }
    }
    cout << ans << endl;
    return 0;
}