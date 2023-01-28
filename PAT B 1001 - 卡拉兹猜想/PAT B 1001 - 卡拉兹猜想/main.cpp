//
//  main.cpp
//  PAT B 1001 - 卡拉兹猜想
//
//  Created by 97 on 2019/7/19.
//  Copyright © 2019 97. All rights reserved.
//

#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int i = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        }else{
            n = (3 * n + 1) / 2;
        }
        i++;
    }
    printf("%d", i);
}
