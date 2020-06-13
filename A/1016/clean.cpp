#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct Time {
    int dd, hh, mm;
};

const int maxn = 1010;
const int aday = 1440;

int toll[26], accu[26];
char st[10], name[22], flag;
char names[maxn][22];
int ids[maxn];
vector<Time> lon[maxn];  // list for on-line
vector<Time> loff[maxn]; // list for off-line
int N, tmp, pp = 0, nid;
int sum;
int yy, dd, hh, mm;

bool ncmp(int a, int b) {
    if (strcmp(names[a], names[b]) <= 0) {
        return true;
    } else {
        return false;
    }
}

bool tcmp(Time aa, Time bb) {
    if (aa.dd < bb.dd) {
        return true;
    }
    if (aa.dd > bb.dd) {
        return false;
    }
    if (aa.hh < bb.hh) {
        return true;
    }
    if (aa.hh > bb.hh) {
        return false;
    }
    if (aa.mm < bb.mm) {
        return true;
    }
    return false;
}

int piecewise(int t) {
    int s = (t / aday) * accu[24] * 60;
    t = t % aday;
    int tmp = t / 60;
    s += accu[tmp] * 60;
    t %= 60;
    s += t * toll[tmp];
    return s;
}

int compute(Time on, Time off) {
    int bill, t1, t2;
    printf("%02d:%02d:%02d %02d:%02d:%02d ", on.dd, on.hh, on.mm, off.dd,
           off.hh, off.mm);
    // t1, t2均为从on的那一天的零点零分开始计算得到的分钟数
    // 二者相减即为时长
    // piecewise(t) 为从零点零分开始打电话，打到t分钟时的花费
    // 于是 piecewise(t2) - piecewise(t1) 即为实际花费
    t1 = on.hh * 60 + on.mm;
    t2 = (off.dd - on.dd) * aday + off.hh * 60 + off.mm;
    bill = piecewise(t2) - piecewise(t1);
    printf("%d $%.2f\n", t2 - t1, bill / 100.);
    return bill;
}

int main(void) {
    for (int i = 0; i < 24; i++) {
        cin >> toll[i];
        accu[i + 1] = accu[i] + toll[i]; // 累积
    }
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%s %d:%d:%d:%d %s", name, &yy, &dd, &hh, &mm, st);
        flag = true;
        for (int j = 0; j < pp; j++) { // 查找名字对应id
            if (strcmp(names[j], name) == 0) {
                nid = j; // 找到对应id
                flag = false;
                break;
            }
        }
        if (flag) { // 该名字未出现过
            strcpy(names[pp], name);
            ids[pp] = pp; // index初始化，排序用
            nid = pp++;
        }
        Time event = {.dd = dd, .hh = hh, .mm = mm};
        if (strcmp(st, "on-line") == 0) {
            // 按事件类型将Time结构体放入对应的vector
            lon[nid].push_back(event);
        } else {
            loff[nid].push_back(event);
        }
    }
    sort(ids, ids + pp, ncmp); // index按字典序排序

    // 开始计算和输出
    for (int i = 0; i < pp; i++) {
        nid = ids[i]; // 按字典序取id
        sum = 0;
        flag = true;
        // printf("%s %02d\n", names[nid], yy); // 打印名字和月份
        sort(lon[nid].begin(), lon[nid].end(), tcmp);
        sort(loff[nid].begin(), loff[nid].end(), tcmp);
        // 排序完后开始配对
        auto it1 = lon[nid].begin();
        auto it2 = loff[nid].begin();
        while (it1 != lon[nid].end() && it2 != loff[nid].end()) {
            if (tcmp(*it1, *it2)) {
                if (flag) {
                    flag = false;
                    printf("%s %02d\n", names[nid], yy); // 打印名字和月份
                }
                if ((it1 + 1) != lon[nid].end() && tcmp(*(it1 + 1), *it2)) {
                    it1++;
                    continue;
                }
                sum += compute(*it1, *it2); // 计算一个pair的花费信息并打印
                it1++;
                it2++;
            } else {
                it2++;
            }
        }
        printf("Total amount: $%.2f\n", sum / 100.);
    }

    return 0;
}