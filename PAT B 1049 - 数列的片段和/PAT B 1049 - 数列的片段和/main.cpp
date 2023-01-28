//
//  main.cpp
//  PAT B 1049 - 数列的片段和
//
//  Created by 97 on 2019/8/13.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

double a[100010];

int main(){
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%lf", &a[i]);
    }
    double out = 0;
    for (int i = 0; i < N; i++) {
        out += a[i] * (N - i) * (i + 1);
    }
//      超时
//    for (int start = 0; start < N; start++) {
//        double comment = 0;
//        for (int end = start; end < N; end++) {
//            comment += a[end];
//            out += comment;
//        }
//    }
    printf("%.2lf", out);
}
