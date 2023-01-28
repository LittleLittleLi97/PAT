//
//  main.cpp
//  PAT B 1047 - 编程团体赛
//
//  Created by 97 on 2019/8/12.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int a[1010] = {0};

int main(){
    int N;
    scanf("%d", &N);
    int which, person, grade;
    for (int i = 0; i < N; i++) {
        scanf("%d-%d %d", &which, &person, &grade);
        a[which] += grade;
    }
    int out = 0;
    for (int i = 0; i < 1010; i++) {
        if (a[i] > a[out]) {
            out = i;
        }
    }
    printf("%d %d", out, a[out]);
}
