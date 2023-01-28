//
//  main.cpp
//  PAT B 1029 - 旧键盘
//
//  Created by 97 on 2019/7/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <string.h>

bool ever[200] = {false};

int main(){
    char a[100];
    char b[100];
    scanf("%s", a);
    scanf("%s", b);
    for (int i = 0; i < 100; i++) {
        if (a[i] >= 'a' && a[i] <= 'z') {
            a[i] -= 32;
        }
        if (b[i] >= 'a' && b[i] <= 'z') {
            b[i] -= 32;
        }
    }
    //    printf("%s\n%s", a, b);7_This_is_a_test
    for (int i = 0; i < strlen(a); i++) {
//        printf(" - i - %d - \n", i);
        int flag = 0;
        for (int j = 0; j < strlen(b); j++) {
            if (a[i] == b[j]) {
                flag = 1;
                break;
            }
        }
        if (flag == 0 && ever[(int)a[i]] == false) {
            ever[(int)a[i]] = true;
            printf("%c", a[i]);
        }
    }
}
