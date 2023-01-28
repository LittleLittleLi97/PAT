//
//  main.cpp
//  PAT B 1063 - 计算谱半径
//
//  Created by 97 on 2019/9/1.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    double a, b;
    double m = 0;
    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        double out = sqrt(a * a + b * b);
        if (m < out) m = out;
    }
    printf("%.2lf", m);
}
