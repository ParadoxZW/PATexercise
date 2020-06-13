/**
 * 用结构体尽量还原
 */
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

// struct Call {
//     Time on;
//     Time off;
// };

const int maxn = 1010;
const int aday = 1440;

int toll[26], accu[26];
bool status[maxn];
char st[10], name[22], flag;
char names[maxn][22];
int ids[maxn];
Time atline[maxn];
// vector<Call> list[maxn];
vector<Time> lon[maxn];
vector<Time> loff[maxn];
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
    // Time aa = a.on, bb = b.on;
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
    // cout << s << endl;
    t = t % aday;
    // cout << t << endl;
    int tmp = t / 60;
    // cout << tmp << endl;
    s += accu[tmp] * 60;
    // cout << s << endl;
    t %= 60;
    // cout << t << endl;
    s += t * toll[tmp];
    // cout << s << endl;
    return s;
}

int compute(Time on, Time off) {
    int bill, t1, t2;
    printf("%02d:%02d:%02d %02d:%02d:%02d ", on.dd, on.hh, on.mm, off.dd,
           off.hh, off.mm);
    t1 = on.hh * 60 + on.mm;
    // cout << t1 << endl;
    t2 = (off.dd - on.dd) * aday + off.hh * 60 + off.mm;
    // cout << (off.dd - on.dd) << " " << off.hh << " " << off.mm << endl;
    bill = (piecewise(t2) - piecewise(t1));
    printf("%d $%.2f\n", t2 - t1, bill / 100.);
    return bill;
}

int main(void) {
    for (int i = 0; i < 24; i++) {
        cin >> toll[i];
        accu[i + 1] = accu[i] + toll[i];
    }
    // cout << "1" << endl;

    cin >> N;
    // cout << N << endl;
    for (int i = 0; i < N; i++) {
        // cout << N << endl;
        scanf("%s %d:%d:%d:%d %s", name, &yy, &dd, &hh, &mm, st);
        // cout << name << " " << yy << " " << dd << " " << hh << " " << mm << "
        // "
        //      << st << endl;
        flag = true;
        for (int j = 0; j < pp; j++) {
            if (strcmp(names[j], name) == 0) {
                nid = j;
                flag = false;
                break;
            }
        }
        if (flag) {
            strcpy(names[pp], name);
            ids[pp] = pp;
            nid = pp++;
        }
        // if (strcmp(st, "on-line")) {
        //     status[nid] = true;
        //     Time on = {.dd = dd, .hh = hh, .mm = mm};
        //     atline[nid] = on;
        // } else {
        //     if (status[nid]) {
        //         status[nid] = false;
        //         // paired
        //         Time off = {.dd = dd, .hh = hh, .mm = mm};
        //         Call acal = {.on = atline[nid], .off = off};
        //         list[nid].push_back(acal);
        //     }
        // }
        Time event = {.dd = dd, .hh = hh, .mm = mm};
        if (strcmp(st, "on-line") == 0) {
            // cout << '[' << name << " " << st << " " << nid << endl;
            lon[nid].push_back(event);
        } else {
            // cout << '[' << name << " " << st << " " << nid << endl;
            loff[nid].push_back(event);
        }
    }

    sort(ids, ids + pp, ncmp);
    // cout << '[' << pp << endl;
    for (int i = 0; i < pp; i++) {
        nid = ids[i];
        sum = 0;
        printf("%s %02d\n", names[nid], yy);
        // cout << '[' << lon[nid].size() << endl;
        // cout << '[' << loff[nid].size() << endl;
        sort(lon[nid].begin(), lon[nid].end(), tcmp);
        sort(loff[nid].begin(), loff[nid].end(), tcmp);
        // cout << '[' << "3ok" << endl;
        auto it1 = lon[nid].begin();
        auto it2 = loff[nid].begin();
        while (it1 != lon[nid].end() && it2 != loff[nid].end()) {
            if (tcmp(*it1, *it2)) {
                if ((it1 + 1) != lon[nid].end() && tcmp(*(it1 + 1), *it2)) {
                    it1++;
                    continue;
                }
                sum += compute(*it1, *it2);
                it1++;
                it2++;
            } else {
                it2++;
            }
        }
        // for (auto a : list[nid]) {
        //     sum += compute(a);
        // }

        printf("Total amount: $%.2f\n", sum / 100.);
    }

    return 0;
}