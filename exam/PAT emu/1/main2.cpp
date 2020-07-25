#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    return !b?a:gcd(b, a%b);
}

struct Frac {
    ll up, down;
} a, b;

Frac reduction(Frac r) {
    if (r.down < 0) {
        r.up = -r.up;
        r.down = -r.down;
    }
    if (r.up == 0) {
        r.down = 1;
    } else {
        int d = gcd(abs(r.up), abs(r.down));
        r.up /= d;
        r.down /= d;
    }
    return r;
}

Frac add(Frac f1, Frac f2) {
    Frac r;
    r.up = f1.up * f2.down + f2.up * f1.down;
    r.down = f1.down * f2.down;
    return reduction(r);
}

Frac minu(Frac f1, Frac f2) {
    Frac r;
    r.up = f1.up * f2.down - f2.up * f1.down;
    r.down = f1.down * f2.down;
    return reduction(r);
}

Frac mult(Frac f1, Frac f2) {
    Frac r;
    r.up = f1.up * f2.up;
    r.down = f1.down * f2.down;
    return reduction(r);
}

Frac divide(Frac f1, Frac f2) {
    Frac r;
    r.up = f1.up * f2.down;
    r.down = f1.down * f2.up;
    return reduction(r);
}

void showResult(Frac r) {
    r = reduction(r);
    if(r.up < 0)
        printf("(");

    if(r.down == 1) printf("%lld", r.up);
    else if(abs(r.up) > r.down) {
        printf("%lld %lld/%lld", r.up / r.down, abs(r.up) % r.down, r.down);
    }else {
        printf("%lld/%lld", r.up, r.down);
    }

    if (r.up < 0)
        printf(")");
}

int main(void) {
    scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);
    showResult(a);
    printf(" + ");
    showResult(b);
    printf(" = ");
    showResult(add(a, b));
    printf("\n");

    showResult(a);
    printf(" - ");
    showResult(b);
    printf(" = ");
    showResult(minu(a, b));
    printf("\n");

    showResult(a);
    printf(" * ");
    showResult(b);
    printf(" = ");
    showResult(mult(a, b));
    printf("\n");

    showResult(a);
    printf(" / ");
    showResult(b);
    printf(" = ");
    if(b.up == 0) printf("Inf");
    else showResult(divide(a, b));
    printf("\n");
    return 0;
}