#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;

int N, M;
int lt;

int mem[maxn / 3][maxn / 2];
int inp[maxn];
int tap[maxn/3][maxn/3];

int main() {
#ifdef LOCAL
    freopen("./1.txt", "r", stdin);
#endif
    cin >> N >> M;
    while(~scanf("%d", &inp[0]);) {
        for (int i = 1; i < N; i++) {
            scanf("%d", &inp[i]);
        }
        for (int i = 0; i < M; i++) {
            mem[i] = inp[i];
        }
        int p = M, ll = 0, v = -1;
        int idx[maxn/3];
        sort(mem, mem+M);
        while(p < N) {
            if(v==-1)
            tap[ll][idx[ll]] = mem[0];
            else{
                if(v > )
            }
            p++;
        }
    }
    return 0;
}