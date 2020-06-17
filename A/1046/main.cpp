#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn = 100010;
int dis[maxn], N, s, m, x, y, ans;
int tmp, accu[maxn];

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dis[i];
        s += dis[i];
        accu[i+1] = accu[i] + dis[i];
    }
    cin >> m;
    // cout << s << endl;
    while(m--){
        ans = 0;
        cin >> x >> y;
        if (x > y) {
            tmp = x;
            x = y;
            y = tmp;
        }
        ans = accu[y - 1] - accu[x - 1]; 
        ans = min(ans, s - ans);
        cout << ans << endl;
    }
    return 0;
}