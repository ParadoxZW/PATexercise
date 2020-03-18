// 测试struct的初始化功能

#include <iostream>
#include <stdio.h>
using namespace std;

struct A{
    int a;
    int b;
    A(int a, int b){
        this->a = a;
        this->b = b;
    }
}; // compilable

struct A1{
    int a;
    int b;
    A1(int a_, int b_){
        a = a_;
        b = b_;
    }
}; // compilable

struct A2{
    int a;
    int b;
    A2(int a, int b): a(a), b(b) {}
}; // compilable

struct B{
    int a;
    int b;
}; // compilable

int main(void)
{
    //A x = A(1, 2);  // compilable
    //struct A x(1, 2); // compilable
    A2 x(1, 4); // `struct`不是必须的
    printf("%d %d\n", x.a, x.b);
    B xx = {.a = 1, .b = 2};
    //B xx = {a:1, b:2}; // compilable
    //B xx = {1, 2}; // compilable
    printf("%d %d\n", xx.a, xx.b);
    return 0;
}
