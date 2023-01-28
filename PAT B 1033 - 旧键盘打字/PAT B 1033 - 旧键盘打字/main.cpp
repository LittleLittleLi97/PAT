//
//  main.cpp
//  PAT B 1033 - 旧键盘打字
//
//  Created by 97 on 2019/7/31.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

bool ascii[200] = {false};
bool shiftFlag = false;

int main(){
    char a;
    a = getchar();
    while (a != '\n') {
        ascii[(int)a] = true;
        if (a == '+') {
            shiftFlag = true;
        }
        if (a >= 'A' && a <= 'Z') {
            ascii[(int)a + 32] = true;
        }
        if (a >= 'a' && a <= 'z') {
            ascii[(int)a - 32] = true;
        }
        a = getchar();
    }
//    for (int i = 0; i < 200; i++) {
//        printf(" %d - %d\n", i,ascii[i]);
//    }
    a = getchar();
    while (a != '\n') {
        if (ascii[(int)a] != true) {
            if (!(a >= 'A' && a <= 'Z' && shiftFlag == true)) {
                printf("%c", a);
            }
        }
        a = getchar();
    }
}
