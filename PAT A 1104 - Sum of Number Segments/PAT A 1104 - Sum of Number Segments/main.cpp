//
//  main.cpp
//  PAT A 1104 - Sum of Number Segments
//
//  Created by 97 on 2019/11/9.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int N;

int main(){
    scanf("%d", &N);
    double out = 0;
    for (int i = 0; i < N; i++) {
        double t; scanf("%lf", &t);
        out += (double)(N - i) * (double)(i + 1) * t;
    }
    printf("%.2lf", out);
}
