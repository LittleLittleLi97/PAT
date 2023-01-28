//
//  main.cpp
//  PAT B 1026 - 程序运行时间
//
//  Created by 97 on 2019/7/29.
//  Copyright © 2019 97. All rights reserved.
//

#include <stdio.h>

int main(){
    long int a, b;
    scanf("%ld%ld", &a, &b);
    double total = (double)(b - a) / 100;
    int hh = total / 60 / 60;
    total -= hh * 60 * 60;
    int mm = total / 60;
    total -= mm * 60;
    int ss;
    if (total - (int)total >= 0.5) {
        total += 1;
    }
    ss = total;
    printf("%02d:%02d:%02d", hh, mm, ss);
}
