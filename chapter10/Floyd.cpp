int n, m; // n为顶点数，m为边数
int dis[maxn][maxn];

void floyd() {
    fill(dis, dis + maxn * maxn, inf);
    for (int i = 0; i < N; i++) {
        dis[i][i] = 0;
    }
    /* scanf dis[i][j] */

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dis[i][k] != inf && dis[k][j] != inf &&
                    dis[i][j] > dis[i][k] + dis[k][j]) {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}