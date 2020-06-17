#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
// #include <mat_print.hpp>
using namespace std;

int m, n, k;
int r, out, nin, x, top;
int last, maxn;
bool flag;
vector<int> v;

int main(void) {
    cin >> m >> n >> k;
    for (int i = 0; i < k; i++) {
        maxn = m;
        out = 1;
        flag = true;
        for (int j = 0; j < n; j++) {
            scanf("%d", &x);
            if (flag) {
                if (x > maxn) {
                    flag = false;
                    cout << "NO" << endl;
                }
                maxn++;
                if(x > last){
                    if(x < lg){
                        flag = false;
                        cout << "NO" << endl;
                    }else {
                        last = x;
                        lg = x;
                        // continue; 
                    }
                }else{
                    if(x != ls - 1){
                        flag = false;
                        cout << "NO" << endl;
                    }else{
                        ls--;
                        last = x;
                    }
                }
            }
        }
        if (flag) {
            cout << "YES" << endl;
        }
    }

    return 0;
}