/**
 * 同分要共享排名（1，2，2，2，5）
 * 学号可以直接当作数字，作为数组的索引
 */
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 2010;

int grades[maxn][4], ranks[maxn][4], n;
int rank1[maxn];
int rank2[maxn];
int rank3[maxn];
int rank4[maxn];
char code[maxn][12], tmp[12];
char best_c[maxn];
int best_r[maxn];
int flag, N, M;

bool cmp1(int x, int y) { return grades[x][3] > grades[y][3]; }
bool cmp2(int x, int y) { return grades[x][0] > grades[y][0]; }
bool cmp3(int x, int y) { return grades[x][1] > grades[y][1]; }
bool cmp4(int x, int y) { return grades[x][2] > grades[y][2]; }

void fillr(int *rank_, int k) {
    int rr = 0, gg = 0;
    for (int i = 0; i < N; i++) {
        n = rank_[i];
        if (grades[n][k] != gg) {
            rr = ranks[n][k] = i + 1;
            gg = grades[n][k];
        } else {
            ranks[n][k] = rr;
        }
    }
}

int main(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> code[i] >> grades[i][0] >> grades[i][1] >> grades[i][2];
        grades[i][3] = (grades[i][0] + grades[i][1] + grades[i][2]); // / 3;
        rank1[i] = rank2[i] = rank3[i] = rank4[i] = i;
    }
    sort(rank1, rank1 + N, cmp1);
    sort(rank2, rank2 + N, cmp2);
    sort(rank3, rank3 + N, cmp3);
    sort(rank4, rank4 + N, cmp4);

    fillr(rank1, 3);
    fillr(rank2, 0);
    fillr(rank3, 1);
    fillr(rank4, 2);

    for (int i = 0; i < N; i++) {
        if (ranks[i][3] <= ranks[i][0] && ranks[i][3] <= ranks[i][1] &&
            ranks[i][3] <= ranks[i][2]) {
            best_r[i] = ranks[i][3];
            best_c[i] = 'A';
        } else if (ranks[i][0] <= ranks[i][1] && ranks[i][0] <= ranks[i][2]) {
            best_r[i] = ranks[i][0];
            best_c[i] = 'C';
        } else if (ranks[i][1] <= ranks[i][2]) {
            best_r[i] = ranks[i][1];
            best_c[i] = 'M';
        } else {
            best_r[i] = ranks[i][2];
            best_c[i] = 'E';
        }
    }

    // for (int i = 0; i < N; i++) {
    //     n = rank1[i];
    //     if (best_r[n] == 0) {
    //         best_r[n] = i + 1;
    //         best_c[n] = 'A';
    //     }
    //     n = rank2[i];
    //     if (best_r[n] == 0) {
    //         best_r[n] = i + 1;
    //         best_c[n] = 'C';
    //     }
    //     n = rank3[i];
    //     if (best_r[n] == 0) {
    //         best_r[n] = i + 1;
    //         best_c[n] = 'M';
    //     }
    //     n = rank4[i];
    //     if (best_r[n] == 0) {
    //         best_r[n] = i + 1;
    //         best_c[n] = 'E';
    //     }
    // }
    for (int i = 0; i < M; i++) {
        cin >> tmp;
        flag = 1;
        for (int j = 0; j < N; j++) {
            if (strcmp(code[j], tmp) == 0) {
                cout << best_r[j] << " " << best_c[j] << endl;
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "N/A" << endl;
        }
    }
    return 0;
}