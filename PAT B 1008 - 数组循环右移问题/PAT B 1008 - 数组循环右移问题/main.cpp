//
//  main.cpp
//  PAT B 1008 - 数组循环右移问题
//
//  Created by 97 on 2019/7/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int a[110];

int main(){
//    既然要移动数据的次数尽量少，那干脆一次都不要移
    int n;
    int m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n; i++) {
        printf("%d", a[(n - (m % n) + i) % n]);
        if (i != n - 1) {
            printf(" ");
        }
    }
}
