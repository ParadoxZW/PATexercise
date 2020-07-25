#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000;
int oa[maxn];
int sa[maxn];
int xa[maxn];
int N;

bool compare(int *x, int *y){
    for (int i = 0; i < N; i++) {
        if (x[i] != y[i]) {
            return false;
        }
    }
    return true;
}

bool insert_s() {
    for (int i = 1; i < N; i++){
        for (int j = i; j > 0; j--) {
            if (xa[j] >= xa[j-1]) {
                break;
            } else{
                int tmp = xa[j];
                xa[j] = xa[j-1];
                xa[j-1]=tmp;
            }
        }
        if(compare(xa, sa)) {
            // while(i++) {
            //     if(xa[i] != sa[i]) {
            //         break;
            //     }
            // }
            i++;
            for (int j = i; j > 0; j--) {
                if (xa[j] >= xa[j - 1]) {
                    break;
                } else {
                    int tmp = xa[j];
                    xa[j] = xa[j - 1];
                    xa[j - 1] = tmp;
                }
            }
            printf("Insertion Sort\n"); 
            return true;
        }
    }
    return false;
}

void merge_s() {
    int l , r;
    int d = 1;
    while(true){
        d *= 2;
        for(int i=0; i<N; i+=d){
            r= min(i+d, N);
            sort(xa+i, xa+r);
        }
        // printf("x\n");
        if(compare(xa, sa)) {
            d *= 2;
            for (int i = 0; i <N; i +=d) {
                r = min(i + d, N);
                sort(xa + i, xa + r);
            }
            return;
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        scanf("%d", oa+i);
    }
    for (int i = 0; i < N; i++) {
        scanf("%d", sa + i);
    }
    for (int i = 0; i < N; i++) {
        xa[i] = oa[i];
    }
    bool flag = insert_s();
    if (!flag) {
        for (int i = 0; i < N; i++) {
            xa[i] = oa[i];
        }
        printf("Merge Sort\n");
        merge_s();
    }
    cout << xa[0];
    for (int i=1;i<N;i++){
        printf(" %d", xa[i]);
    }
    cout << endl;
    return 0;
}