#include <bits/stdc++.h>
using namespace std;

const int maxn = 1100;
int N;
int arr[maxn];
int path[maxn];
int flag = 0;

void output(int nth) {
    printf("%d", path[0]);
    for (int i = 1; i < nth; i++) {
        printf(" %d", path[i]);
    }
    printf("\n");
}

void dfs(int k, int nth) {
    if (k * 2 > N) {
        output(nth);
        return;
    }
    if (k*2+1 <= N) {
        path[nth] = arr[k * 2 + 1];
        if (path[nth] < path[nth - 1]) {
            if (flag == 0) {
                flag = 1;
            } else if (flag == 2) {
                flag = 3;
            }
        } else if (path[nth] > path[nth - 1]) {
            if (flag == 0) {
                flag = 2;
            } else if (flag == 1) {
                flag = 3;
            }
        }
        dfs(k * 2 + 1, nth + 1);
    }
    path[nth] = arr[k*2];
    if (path[nth] < path[nth - 1]) {
        if (flag == 0) {
            flag = 1;
        }else if(flag == 2) {
            flag = 3;
        }
    } else if (path[nth] > path[nth - 1]) {
        if (flag == 0) {
            flag = 2;
        } else if (flag == 1) {
            flag = 3;
        }
    }
    dfs(k * 2, nth+1);
}

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        scanf("%d", arr+i);
    }
    path[0] = arr[1];
    dfs(1, 1);
    if (flag == 1) {
        std::cout << "Max Heap" << std::endl;
    } else if (flag == 2) {
        std::cout << "Min Heap" << std::endl;
    } else {
        std::cout << "Not Heap" << std::endl;
    }

    return 0;
}