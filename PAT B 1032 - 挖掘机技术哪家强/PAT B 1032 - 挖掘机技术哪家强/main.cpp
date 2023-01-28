//
//  main.cpp
//  PAT B 1032 - 挖掘机技术哪家强
//
//  Created by 97 on 2019/7/30.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
using namespace std;

int a[100010] = {0};

int main(){
    int N;
    scanf("%d", &N);
    int where;
    int grade;
    for (int i = 0; i < N; i++) {
        scanf("%d%d", &where, &grade);
        a[where] += grade;
    }
    int k = 0;
    for (int i = 0; i <= N; i++) {
        if (a[i] > a[k]) {
            k = i;
        }
    }
    printf("%d %d", k, a[k]);
}
