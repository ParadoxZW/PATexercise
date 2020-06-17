for (int i = 1; i <= N; i++) {
    for (int v = w[i]; v <= V; v++) {
        dp[v] = max(dp[v], dp[v - w[i]] + c[i]);
    }
}