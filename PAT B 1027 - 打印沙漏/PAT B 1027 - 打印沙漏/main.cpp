//
//  main.cpp
//  PAT B 1027 - 打印沙漏
//
//  Created by 97 on 2019/7/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int main(){
    int many;
    scanf("%d", &many);
    getchar();
    char c;
    c = getchar();
    int i = 0;
    if (many != 0) {
        i++;
        many -= 1;
    }
    while (many) {
        if (many >= (i+2) * 2) {
            many -= (i+2) * 2;
            i += 2;
        }else break;
    }
//    printf(" - hang:%d - shengyu:%d - \n", i, many);
    for (int j = i; j > 0; j -= 2) {
        for (int k = 0; k < (i - j) / 2; k++) {
            printf(" ");
        }
        for (int k = 0; k < j; k++) {
            printf("%c", c);
        }
        if (j != 1) {
            printf("\n");
        }
    }
    for (int j = 3; j <= i; j += 2) {
        printf("\n");
        for (int k = 0; k < (i - j) / 2; k++) {
            printf(" ");
        }
        for (int k = 0; k < j; k++) {
            printf("%c", c);
        }
    }
//    if (many) {
        printf("\n%d", many);
//    }
}
