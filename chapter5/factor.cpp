struct factor {
    int x, cnt;
}fac[10];

int rt = sqrt(n); 
while (prime[i] <= rt) {
    int p = prime[i];
    if(n%p==0){
        fac[num].x = p;
        fac[num].cnt = 0;
        while(n%p==0){
            fac[num].cnt++;
            n /= p;
        }
        num++;
    }
    i++;
}
if(n!=1){
    fac[num].x=n;
    fac[num++].cnt=1;
}

// 计算n!中有多少个质因子p
int cal(int n, int p) {
    if (n < p) return 0;
    return n/p + cal(n/p , p);
}