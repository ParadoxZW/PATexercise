#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int maxl = 10010;
bool ct[maxl][maxl] = {};
bool vis[maxl][maxl] = {}, flag;
int T, n, m, k, x, y, xx, yy;
typedef struct position{
    int x, y;
} POS;

int main(void)
{
    scanf("%d", &T);
    while(T--){
        flag = true;
        scanf("%d %d %d", &n, &m, &k);
        for (int i = 0; i<=n;i++){
        fill(*(ct+i), *(ct+i)+m+1, false); // 剪枝
        fill(*(vis+i), *(vis+i)+m+1, false); // 剪枝
        }
        queue<POS> pv;
        for (int i = 0; i<k;i++){
            scanf("%d %d", &x, &y);
            ct[x-1][y-1] = true;
        }
        x = (n + 1) / 2 - 1;
        y = m / 2 - 1;
        POS p, t;
        p.x = x;
        p.y = y;
        pv.push(p);
        while(pv.size()){
            t = pv.front();
            pv.pop();
            xx = t.x;
            yy = t.y;
            //cout << xx << " "<< yy << endl;
            if (!ct[xx][yy] && !ct[xx][yy+1]){
                printf("(%d,%d) (%d,%d)\n", xx+1, yy+1, xx+1, yy + 2);
                flag = false;
                break;
            }
            vis[xx][yy] = true;
            if(xx - 1>=0 && !vis[xx-1][yy]){
                POS p1;
                p1.x = xx -1;
                p1.y = yy;
                pv.push(p1);
            }
            if(yy - 1 >= 0 && !vis[xx][yy -1]){
                POS p2;
                p2.x = xx;
                p2.y = yy -1;
                pv.push(p2);
            }
            if(yy + 1 < m - 1 && !vis[xx][yy +1]){
                POS p3;
                p3.x = xx;
                p3.y = yy +1;
                pv.push(p3);
            }
            if(xx + 1 < n && !vis[xx+1][yy]){
                POS p4;
                p4.x = xx+1;
                p4.y = yy;
                pv.push(p4);
            }
        }
        if(flag)
            printf("-1\n");
    }
    return 0;
}
