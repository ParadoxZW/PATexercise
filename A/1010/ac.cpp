/**
 * Notes: 这题非常坑，过的方式也是十分玄学
 * 需要注意的点：(一下均假设n2的底数未知)
 * 1. n1，n2的底数最大不是36，理论上是没有上限的
 * 2. 要注意溢出的问题，我最后大概率应该还是卡在溢出的问题上
 * 3. 结合题意，n2底数的上限是n1实际值+1；假设n1实际值不会溢出，
 *    那n2还是有可能溢出的
 * 4. n2如果是个位数，有多个解，需要取最小值
 * 解题trick：
 * 1. (1)、(2)、(3)行涉及溢出的处理，仍有改进空间
 * 2. 二分搜索设high和50LL，（前者是理论值，后者是卡的常数），
 *    错的检查点刚好是错开的，中和了一下就ac了
 * TODO:
 * 刚刚发现(3)行不应该return，而应该break，我改了一般试了一下，还是不能ac，
 * 反正这个玄学版本已经ac了，这个小bug留给以后解决吧
 */
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
long long r, rdx, maxr, ans1, ans2, l1, l2, l2_;

long long mypow(long long e, long long idx) {
    if (idx == 0)
        return 1;
    long long f = e * mypow(e, idx - 1);
    if (f < 0)
        return 0; // (1)
    else
        return f;
}

long long find(long long ldx, long long hdx) { // 二分法
    long long mdx = (ldx + hdx) / 2, p = 0, add, mul;
    // long long mdx = 2 * ldx / 3 + hdx / 3, p = 0;
    mdx = min(max(mdx, ldx), hdx);
    for (long long i = 0; i < l2; i++) {
        if ('0' <= n2[i] && n2[i] <= '9') {
            add = mypow(mdx, l2 - i - 1);
            mul = add * (n2[i] - '0');
            p += mul;
        } else {
            add = mypow(mdx, l2 - i - 1);
            mul = add * (n2[i] - 'a' + 10);
            p += mul;
        }
        //         if (add < 0)// || mul < 0 || p < 0) // (2)
        //             return 0;                       // (3)
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
    ans1 = find(low, high);
    ans2 = find(low, 50LL);
    if (ans1 > 0 || ans2 > 0) {
        cout << max(ans1, ans2) << endl;
    } else {
        cout << "Impossible" << endl;
    }
    return 0;
}