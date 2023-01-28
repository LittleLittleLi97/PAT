//
//  main.cpp
//  PAT B 1051 - 复数乘法
//
//  Created by 97 on 2019/8/27.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
    double r1,p1,r2,p2;
    cin >> r1 >> p1 >> r2 >> p2;
    double R = r1 * r2;
    double P = p1 + p2;
    double a = R * cos(P);
    double b = R * sin(P);
    bool flag = false;
    if (abs(a) < 0.005) {
        printf("0.00");
        flag = true;
    }else printf("%.2lf", a);
    if (abs(b) < 0.005) {
        if (flag == true) printf("0.00i");
    }else if (b > 0) printf("+%.2lfi", b);
    else printf("%.2lfi", b);
}
