//
//  main.cpp
//  PAT B 1023 - 组个最小数
//
//  Created by 97 on 2019/7/19.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int a[10] = {0};

int main(){
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i < 10; i++) {
        if (a[i] != 0) {
            printf("%d", i);
            a[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < a[i]; j++) {
            printf("%d", i);
        }
    }
}
