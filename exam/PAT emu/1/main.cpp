#include <bits/stdc++.h>

using namespace std;

struct number {
    long long a, b;
    long long sign;
    bool is_zero;
    long long k;
};
number x1, x2;

long long gcd(long long a, long long b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

void regular(number &x) {
    if (x.b < 0) {
        x.a = -x.a;
        x.b = -x.b;
    }
    if (x.a == 0) {
        x.is_zero = true;
        x.sign = 1;
        // x.b = 1;
    } else if (x.a < 0) {
        x.is_zero = false;
        x.a = -x.a;
        x.sign = -1;
    } else {
        x.is_zero = false;
        x.sign = 1;
    }
    if (!x.is_zero) {
        long long g = gcd(x.a, x.b);
        x.a /= g;
        x.b /= g;
    }
}

void printn(number x) {
    if (x.a == 0) {
        printf("0");
        return;
    }
    if (x.sign == -1) {
        printf("(-");
    }

    long long k = x.a / x.b;
    long long a = x.a % x.b;
    long long b = x.b;
    if (k != 0 && a == 0) {
        printf("%lld", k);
    } else if (k != 0) {
        printf("%lld %lld/%lld", k, a, b);
    } else {
        printf("%lld/%lld", a, b);
    }

    if (x.sign == -1) {
        printf(")");
    }
}

void add() {
    number s;
    s.a = x1.sign * x1.a * x2.b + x2.sign * x2.a * x1.b;
    s.b = x1.b * x2.b;
    regular(s);
    printn(x1);
    printf(" + ");
    printn(x2);
    printf(" = ");
    printn(s);
}

void minu() {
    number s;
    s.a = x1.sign * x1.a * x2.b - x2.sign * x2.a * x1.b;
    s.b = x1.b * x2.b;
    regular(s);
    printn(x1);
    printf(" - ");
    printn(x2);
    printf(" = ");
    printn(s);
}

void prod() {
    number s;
    s.a = x1.sign * x1.a * x2.sign * x2.a;
    s.b = x1.b * x2.b;
    regular(s);
    printn(x1);
    printf(" * ");
    printn(x2);
    printf(" = ");
    printn(s);
}

void quot() {
    if (x2.is_zero) {
        printn(x1);
        printf(" / ");
        printn(x2);
        printf(" = ");
        printf("Inf");
        return;
    }
    number s;
    s.a = x1.sign * x1.a * x2.sign * x2.b;
    s.b = x1.b * x2.a;
    regular(s);
    printn(x1);
    printf(" / ");
    printn(x2);
    printf(" = ");
    printn(s);
}

int main() {
    scanf("%lld/%lld %lld/%lld", &x1.a, &x1.b, &x2.a, &x2.b);
    regular(x1);
    regular(x2);
    // cout << x2.a << " " << x2.b << endl;
    add();
    printf("\n");
    minu();
    printf("\n");
    prod();
    printf("\n");
    quot();
    printf("\n");

    return 0;
}