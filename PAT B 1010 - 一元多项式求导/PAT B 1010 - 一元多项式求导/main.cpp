//
//  main.cpp
//  PAT B 1010 - 一元多项式求导
//
//  Created by 97 on 2019/7/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

struct Node {
    int xishu;
    int zhishu;
}a[10010];

int main(){
    int i = 0;
    char flag;
    scanf("%d%d", &a[i].xishu, &a[i].zhishu);
    i++;
    flag = getchar();
    while (flag == ' ') {
        scanf("%d%d", &a[i].xishu, &a[i].zhishu);
        i++;
        flag = getchar();
    }
    for (int j = 0; j < i; j++) {
        a[j].xishu *= a[j].zhishu--;
        if (a[j].xishu) {
            printf("%d %d", a[j].xishu, a[j].zhishu);
        }
        if (a[j + 1].zhishu != 0) {
            printf(" ");
        }
    }
    if (a[0].xishu == 0) {
        printf("0 0");
    }
}
