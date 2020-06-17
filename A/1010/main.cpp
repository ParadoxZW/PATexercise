#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#define str_as(a, b) sprintf((a), "%s", (b))
using namespace std;

char n1[12];
char n2[12];
char tmp[12];
int tag;
long long r, rdx, maxr, ans, l1, l2, l2_;

long long mypow(long long e, long long idx) {
    if (idx == 0)
        return 1;
    long long f = e * mypow(e, idx - 1);
    if (f < 0)
        return 0;
    else
        return f;
}

long long find(long long ldx, long long hdx) { // 二分法
    long long mdx = (ldx + hdx) / 2, p = 0, add;
    // long long mdx = 2 * ldx / 3 + hdx / 3, p = 0;
    mdx = min(max(mdx, ldx), hdx);
    for (long long i = 0; i < l2; i++) {
        if ('0' <= n2[i] && n2[i] <= '9') {
            add = mypow(mdx, l2 - i - 1) * (n2[i] - '0');
            p += add;
        } else {
            add = mypow(mdx, l2 - i - 1) * (n2[i] - 'a' + 10);
            p += add;
        }
        if (add <= 0)
            return 0;
    }
    long long tmp = 0;
    if (p == r) {
        return mdx;
    } else if (p < r) {
        if (mdx + 1 <= hdx) {
            tmp = find(mdx + 1, hdx);
        }
    } else {
        if (mdx - 1 >= ldx) {
            tmp = find(ldx, mdx - 1);
        }
    }
    return tmp;
}

int main(void) {
    scanf("%s %s %d %lld", n1, n2, &tag, &rdx);
    if (tag == 2) {
        str_as(tmp, n1);
        str_as(n1, n2);
        str_as(n2, tmp);
    }
    l1 = strlen(n1);
    l2_ = l2 = strlen(n2);
    for (long long i = 0; i < l1; i++) {
        if ('0' <= n1[i] && n1[i] <= '9') {
            r += mypow(rdx, l1 - i - 1) * (n1[i] - '0');
        } else {
            r += mypow(rdx, l1 - i - 1) * (n1[i] - 'a' + 10);
        }
    }
    for (long long i = 0; i < l2; i++) {
        if (maxr == 0 && '0' == n2[i]) {
            l2_--;
        }
        if ('0' <= n2[i] && n2[i] <= '9') {
            maxr = max(maxr, (n2[i] - '0') * 1LL);
        } else {
            maxr = max(maxr, n2[i] - 'a' + 10LL);
        }
    }
    if (l2_ == 1 && maxr == r) {
        cout << maxr + 1 << endl;
        return 0;
    }
    long long low = maxr + 1LL;
    long long high = max(low, r) + 1LL;
    ans = find(low, high);
    if (ans > 0) {
        cout << ans << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}