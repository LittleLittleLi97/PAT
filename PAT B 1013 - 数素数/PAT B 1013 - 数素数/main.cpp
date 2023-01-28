//
//  main.cpp
//  PAT B 1013 - 数素数
//
//  Created by 97 on 2019/7/21.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int pd(int a){
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) {
            return 0;
        }
    }
    return 1;
}

void out(int a, int b){
    if (b % 10 != 0) {
        printf(" ");
    }
    printf("%d", a);
    if (b % 10 == 9) {
        printf("\n");
    }
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    int sushucount = 0;
    int ceshishu = 2;
    while (sushucount < n) {
        if (pd(ceshishu)) {
            sushucount++;
            if (sushucount >= m) {
                out(ceshishu, sushucount - m);
            }
        }
        ceshishu++;
    }
}
