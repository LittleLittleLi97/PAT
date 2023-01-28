//
//  main.cpp
//  PAT 1088 - Rational Arithmetic
//
//  Created by 97 on 2019/11/13.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
    long long up;
    long long down;
};
Node x, y;
Node out;

long long gcd(long long a, long long b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void Adjust(){
    long long g = gcd(abs(out.up), out.down);
    out.up /= g;
    out.down /= g;
}

void Add(){
    out.up = x.up * y.down + y.up * x.down;
    out.down = x.down * y.down;
    Adjust();
}

void De(){
    out.up = x.up * y.down - y.up * x.down;
    out.down = x.down * y.down;
    Adjust();
}

void Mul(){
    out.up = x.up * y.up;
    out.down = x.down * y.down;
    Adjust();
}

void Div(){
    out.up = x.up * y.down;
    out.down = x.down * y.up;
    if (out.down < 0) {
        out.up = -out.up;
        out.down = -out.down;
    }
    Adjust();
}

void PrintOut(Node t){
    if (t.up == 0){
        printf("0");
        return;
    }
    if (t.up < 0) printf("(");
    if (abs(t.up) >= t.down){
        printf("%lld", t.up / t.down);
        if (abs(t.up) % t.down != 0) {
            printf(" %lld/%lld", abs(t.up) % t.down, t.down);
        }
    }else printf("%lld/%lld", t.up, t.down);
    if (t.up < 0) printf(")");
}

int main(){
    scanf("%lld/%lld %lld/%lld", &x.up, &x.down, &y.up, &y.down);
    long long g = gcd(abs(x.up), x.down);
    x.up /= g; x.down /= g;
    g = gcd(abs(y.up), y.down);
    y.up /= g; y.down /= g;
    
    PrintOut(x); printf(" + "); PrintOut(y); printf(" = ");
    Add(); PrintOut(out); printf("\n");
    
    PrintOut(x); printf(" - "); PrintOut(y); printf(" = ");
    De(); PrintOut(out); printf("\n");
    
    PrintOut(x); printf(" * "); PrintOut(y); printf(" = ");
    Mul(); PrintOut(out); printf("\n");
//    printf("%lld / %lld\n", out.up, out.down);
    
    PrintOut(x); printf(" / "); PrintOut(y); printf(" = ");
    if (y.up == 0) printf("Inf");
    else {
        Div(); PrintOut(out);
    }
}
