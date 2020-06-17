#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int k1, k2, m1, m2, m3, cnt;
int n1[12], n2[12];
double a1[12], a2[12], a3[2010] = {0.};
char s[2010];

int main(void) {
    cin >> k1;
    for (int i = 0; i < k1; i++) {
        cin >> n1[i] >> a1[i];
    }
    cin >> k2;
    for (int i = 0; i < k2; i++) {
        cin >> n2[i] >> a2[i];
    }
    m3 = n1[0] + n2[0]; // 最高位指数
    // cout << m1 << " "<< m2 << endl;
    for (int i = 0; i < k1; i++) {
        for (int j = 0; j < k2; j++) {
            a3[n1[i] + n2[j]] += a1[i] * a2[j];
        }
    }

    for (int i = m3; i >= 0; i--) {
        if (fabs(a3[i]) >= 0.05) {
            // cout << i << endl;
            sprintf(s, "%s %d %.1f", s, i, a3[i]);
            cnt++;
        }
    }
    printf("%d%s\n", cnt, s);   
    return 0;
}