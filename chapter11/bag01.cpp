for (int i = 1; i <= N; i++) {
    for (int v = 0; v <= V; v++) {
        if (v >= w[i]) {
            dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - w[i]] + c[i]);
        } else {
            dp[i][v] = dp[i - 1][v];
        }
    }
}

for (int i = 1; i <= N; i++) {
    for (int v = V; v >= w[i]; v--) {
        dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
    }
}