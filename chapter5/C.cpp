typedef long long LL;
LL C(LL n, LL m) {
    LL ans = 1;
    for(LL i=1;i<=m;i++){
        ans = ans * (n-m+i)/i;
    }
    return ans;
}