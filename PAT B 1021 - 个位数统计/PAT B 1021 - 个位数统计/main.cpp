//
//  main.cpp
//  PAT B 1021 - 个位数统计
//
//  Created by 97 on 2019/7/24.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int a[10] = {0};

int main(){
    char n;
    n = getchar();
    while (n != '\n') {
        a[n - '0']++;
        n = getchar();
    }
    int flag = 0;
    for (int i = 0; i < 10; i++) {
        if (a[i] != 0) {
            if (flag == 1) {
                printf("\n");
            }
            printf("%d:%d", i, a[i]);
            flag = 1;
        }
    }
}
