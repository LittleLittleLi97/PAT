//
//  main.cpp
//  PAT A 1065 - A + B and C(64bit)
//
//  Created by 97 on 2019/10/18.
//  Copyright © 2019 97. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long he = a + b;
        if (a > 0 && b > 0 && he < 0) printf("Case #%d: true\n", i);
        // 注意负数溢出判断是 >=
        else if (a < 0 && b < 0 && he >= 0) printf("Case #%d: false\n", i);
        else if (he > c) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
}
