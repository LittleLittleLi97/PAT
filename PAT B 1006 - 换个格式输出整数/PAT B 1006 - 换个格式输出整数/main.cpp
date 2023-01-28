//
//  main.cpp
//  PAT B 1006 - 换个格式输出整数
//
//  Created by 97 on 2019/7/20.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char map[] = {' ', 'S', 'B', 'Q'};

int main(){
    char a[5];
    scanf("%s", a);
    long int len = strlen(a) - 1;
    long int temp = len;
    for (int i = 0; i <= len; i++) {
        for (int j = 0; j < a[i] - '0'; j++) {
            if (temp == 0) {
                printf("%d", j + 1);
            }else{
            printf("%c", map[temp]);
            }
        }
        temp--;
    }
}
