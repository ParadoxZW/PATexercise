#include <bits/stdc++.h>
using namespace std;

const int maxn = 99994400;

// bool isPrime[maxn];
bool vis[maxn];
int N;

void find() {
    // isPrime[2] = true;
    vis[1] = vis[0] = true;
    for (int i = 2; i<=N; i++) {
        if(!vis[i]) {
            // isPrime[i] = true;
            // printf("%d ", i);
            for(int j=i+i;j<=N;j+=i){
                vis[j] = true;
            }
        }
    }
}

char x[10];
int t;
bool flag = true;

int main() {
#ifdef LOCAL
    freopen("./1.txt", "r", stdin);
#endif
    // cin >> N;
    cin.getline(x, 9);
    N = atoi(x);
    find();

    for(int i=0;i<8;i++){
        t = atoi(x+i);
        if(vis[t]) {
            flag = false;
            printf("%s No\n", x + i);
        }else{
            printf("%s Yes\n", x + i);
        }
    }
    if(flag){
        printf("All Prime!\n");
    }

    return 0;
}