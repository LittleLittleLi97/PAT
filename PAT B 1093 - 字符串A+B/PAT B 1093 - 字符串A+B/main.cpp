//
//  main.cpp
//  PAT B 1093 - 字符串A+B
//
//  Created by 97 on 2019/8/16.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

bool a[128] = {false};
bool b[128] = {false};

int main(){

    char n;
    n = getchar();
    while (n != '\n') {
        if (a[n] == false) {
            printf("%c", n);
        }
        a[n] = true;
        n = getchar();
    }
    n = getchar();
    while (n != '\n') {
        if (a[n] == false) {
            printf("%c", n);
        }
        a[n] = true;
//        if (n >= 'a' && n <= 'z') {
//            b[n - 32] = true;
//        }
//        if (n >= 'A' && n <= 'Z') {
//            b[n + 32] = true;
//        }
        n = getchar();
    }
}
