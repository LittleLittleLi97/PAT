//
//  main.cpp
//  PAT B 1062 - 最简分数
//
//  Created by 97 on 2019/9/1.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    else return gcd(b, a % b);
}

int main(){
    double a1, b1, a2, b2, m;
    scanf("%lf/%lf %lf/%lf %lf", &a1, &b1, &a2, &b2, &m);
    double r1 = a1 / b1;
    double r2 = a2 / b2;
    if (r1 > r2) {
        double t = r1;
        r1 = r2;
        r2 = t;
    }
    int count = 0;
    for (double i = 1; i < m; i += 1) {
        if (i / m > r1 && i / m < r2) {
            if(gcd((int)i, (int)m) == 1) {
                if (count > 0) printf(" ");
                printf("%d/%d", (int)i, (int)m);
                count++;
            }
        }
    }
}
