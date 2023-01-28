//
//  main.cpp
//  PAT B 1019 - 数字黑洞
//
//  Created by 97 on 2019/7/23.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int main(){
    int n;
    scanf("%d", &n);
    if (n % 1111 == 0) {
        printf("%04d - %04d = 0000", n, n);
        return 0;
    }
    if (n == 6174) {
        printf("7641 - 1467 = 6174");
        return 0;
    }
    int a, b;
    char t[5] = {'0', '0', '0', '0', '\0'};
    while (n != 6174) {
        for (int i = 0; i < 4; i++) {
            t[i] = n % 10 + '0';
            n /= 10;
        }
        sort(t, t + 4, cmp);
        printf("%s - ", t);
        a = t[0] * 1000 + t[1] * 100 + t[2] * 10 + t[3];
        sort(t, t + 4);
        printf("%s = ", t);
        b = t[0] * 1000 + t[1] * 100 + t[2] * 10 + t[3];
        n = a - b;
        printf("%04d", n);
        if (n != 6174) {
            printf("\n");
        }
    }
}
