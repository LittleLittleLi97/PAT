//
//  main.cpp
//  PAT A 1082 - Rational Sum
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
Node v[110];
int N;

long long gcd(long long a, long long b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        long long a, b;
        scanf("%lld/%lld", &a, &b);
        long long g = gcd(abs(a), abs(b));
        v[i].up = a / g;
        v[i].down = b / g;
    }
    Node out;
    out.up = v[0].up; out.down = v[0].down;
    for (int i = 1; i < N; i++) {
        out.up = out.up * v[i].down + v[i].up * out.down;
        out.down = out.down * v[i].down;
        long long g = gcd(abs(out.up), abs(out.down));
        out.up /= g;
        out.down /= g;
    }
    if (out.up == 0) {
        printf("0");
        return 0;
    }
    if (abs(out.up) > out.down) {
        printf("%lld", out.up / out.down);
        if (abs(out.up) % out.down != 0) printf(" %lld/%lld", abs(out.up) % out.down, out.down);
    }else printf("%lld/%lld", out.up, out.down);
}
