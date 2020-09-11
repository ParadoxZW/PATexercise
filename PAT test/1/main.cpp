#include <bits/stdc++.h>
using namespace std;

const int maxn = 99994400;

bool notPrime[maxn];
int N;

void find() {
    notPrime[1] = notPrime[0] = true;
    for (int i = 2; i<=N; i++) {
        if(!notPrime[i]) {
            for(int j=i+i;j<=N;j+=i){
                notPrime[j] = true;
            }
        }
    }
}

char x[10];
int t;
bool flag = true;

int main() {
    cin.getline(x, 9);
    N = atoi(x);
    find();

    for(int i=0;i<8;i++){
        t = atoi(x+i);
        if(notPrime[t]) {
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