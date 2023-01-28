//
//  main.cpp
//  PAT B 1039 - 到底买不买
//
//  Created by 97 on 2019/8/8.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int a[200] = {0};

int main(){
    char n;
    n = getchar();
    int countStore = 0;
    while (n != '\n') {
        a[n] += 1;
        countStore++;
        n = getchar();
    }
    n = getchar();
    int countBuy = 0;
    int dontEnough = 0;
    while (n != '\n') {
        countBuy++;
        if (a[n] > 0) {
            a[n] -= 1;
        }else dontEnough++;
        n = getchar();
    }
    if (dontEnough) {
        printf("No %d", dontEnough);
    }else {
        printf("Yes %d", countStore - countBuy);
    }
}
