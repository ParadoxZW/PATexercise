typedef long long LL;

LL binaryPow(LL a, LL b, LL m) {
    if(!b) return 1;
    if(b & 1) return a * binaryPow(a, b -1, m) % m;
    else {
        LL mul = binaryPow(a, b>>1, m);
        return mul*mul%m;
    }
}