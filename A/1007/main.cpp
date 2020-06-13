/**
 * 注意读题，第一次没过，输出的是数字不是下标
 */
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 10010;
int a[maxn], K, b[maxn], c[maxn], p, px;
bool flag = true;

int main(void) {
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> a[i];
        if (a[i] >= 0)
            flag = false;
    }
    if (flag) {
        cout << 0 << " " << a[0] << " " << a[K - 1] << endl;
        return 0;
    }
    b[0] = a[0];
    c[0] = 0;
    for (int i = 1; i < K; i++) {
        if (b[i - 1] + a[i] >= a[i]) {
            b[i] = b[i - 1] + a[i];
            c[i] = c[i - 1];
        } else {
            b[i] = a[i];
            c[i] = i;
        }
    }
    p = b[0];
    for (int i = 1; i < K; i++) {
        if (b[i] > p) {
            p = b[i];
            px = i;
        }
    }
    cout << p << " " << a[c[px]] << " " << a[px] << endl;
    return 0;
}