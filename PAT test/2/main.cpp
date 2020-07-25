#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
set<int> ans;
set<int> old;
int M, N;
int x[12][1100];
bool dd[12];
set<int> lose;
int a, b;
int cnt;
#define dif(a, b) (abs((a) - (b)))

int main() {
#ifdef LOCAL
    freopen("./1.txt", "r", stdin);
#endif
    cin >> a >> b;
    // ans.insert(a);
    // ans.insert(b);
    ans.insert(dif(a, b));
    old.insert(a);
    old.insert(b);
    cin >> N >> M;
    cnt = N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &x[i][j]);
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (dd[j]) continue;
            auto it = ans.find(x[j][i]); 
            if (it == ans.end()) { //没找到
                dd[j] = true;
                lose.insert(j);
            }
            else if (old.find(x[j][i]) != old.end()) {  //找到
                dd[j] = true;
                lose.insert(j);
            }
            else {
                old.insert(x[j][i]);
                ans.erase(it);
                for (int k:old) {
                    ans.insert(dif(k, x[j][i]));
                }
            }
        }
        if (!lose.empty()) {
            for(int k:lose){
                printf("Round #%d: %d is out.\n", i+1, k+1);
                cnt--;
            }
        }
        lose.clear();
    }
    if(cnt > 0) {
        printf("Winner(s):");
        for (int i = 0; i < N; i++) {
            if(!dd[i]){
                printf(" %d", i+1);
            }
        }
        printf("\n");
    }else{
        printf("No winner.\n");
    }


    return 0;
}