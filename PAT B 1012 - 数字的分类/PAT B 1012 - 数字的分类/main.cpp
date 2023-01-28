//
//  main.cpp
//  PAT B 1012 - 数字的分类
//
//  Created by 97 on 2019/7/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int temp;
    int a[5] = {0};
    int flag[5] = {0};
    int count = 0;
    int odd = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        if (temp % 2 == 0 && temp % 5 == 0) {
            a[0] += temp;
            flag[0] = 1;
        }
        if (temp % 5 == 1) {
            if (odd % 2 == 0) {
                a[1] += temp;
            }else a[1] -= temp;
            flag[1] = 1;
            odd++;
        }
        if (temp % 5 == 2) {
            a[2]++;
            flag[2] = 1;
        }
        if (temp % 5 == 3) {
            a[3] += temp;
            count++;
            flag[3] = 1;
        }
        if (temp % 5 == 4 && temp > a[4]) {
            a[4] = temp;
            flag[4] = 1;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i == 3) {
            if (flag[3]) {
                printf("%.1f ", (double)a[3] / count);
            }else printf("N ");
            continue;
        }
        if (flag[i]) {
            printf("%d", a[i]);
        }else printf("N");
        if (i != 4) {
            printf(" ");
        }
    }
}
