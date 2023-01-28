//
//  main.cpp
//  PAT B 1038 - 统计同成绩学生
//
//  Created by 97 on 2019/8/8.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int a[110] = {0};
int Find[100010] ={0};

int main(){
    int N;
    int t;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &t);
        a[t] += 1;
    }
    int K;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &t);
        Find[i] = t;
    }
    for (int i = 0; i < K; i++) {
        if (i != 0) printf(" ");
        printf("%d", a[Find[i]]);
    }
}
