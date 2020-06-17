#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn = 100010;

int coins[maxn], N, M, i, j;

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }
    sort(coins, coins + N);
    // cout << coins[0] << endl;
    j = N - 1;
    while(i!=j){
        // cout << i << j << ' ' << coins[i] + coins[j] << ' ' << M << endl;
        if (coins[i] + coins[j] == M){
            cout << coins[i] << " " << coins[j] << endl;
            return 0;
        }else if(coins[i] + coins[j] < M){
            // cout << 'x' << endl;
            i++;
        }else{
            j--;
        }
    }
    cout << "No Solution" << endl;
    return 0;
}